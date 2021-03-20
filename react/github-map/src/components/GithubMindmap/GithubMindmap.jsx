import React, { useEffect, useRef, useState } from "react";
import "./GithubMindmap.css";
import cytoscape from "cytoscape";
import coseBilkent from "cytoscape-cose-bilkent";

cytoscape.use(coseBilkent);
const APIURL = "https://api.github.com/users/";

function GithubMindmap({ user }) {
  const cytoRef = useRef();
  const [mindMap, setMindMap] = useState([]);
  let users = [];

  async function makeMindMap(userName, cnt) {
    if (cnt === 0) {
      setMindMap([
        {
          data: {
            id: userName,
            label: userName,
          },
        },
      ]);
      users = [...users, userName];
    }

    const res = await fetch(APIURL + userName + "/followers");
    const data = await res.json();

    if (data.length > 0) makeData(userName, data.slice(0, 15), cnt + 1);
  }

  function isAlreayExistedUser(userName) {
    for (let i = 0; i < users.length; i++) {
      if (users[i].toLowerCase() === userName.toLowerCase()) {
        return true;
      }
    }
    return false;
  }

  function saveNode(user, data) {
    setMindMap((prevData) => {
      if (!users.includes(data.login)) {
        users = [...users, data.login];
      }
      return [
        ...prevData,
        {
          data: {
            id: data.login,
            url: data.html_url,
            label: data.login,
          },
        },
      ];
    });
  }
  function saveEdge(user, data) {
    setMindMap((prevData) => {
      if (!users.includes(data.login)) {
        users = [...users, data.login];
      }
      return [
        ...prevData,
        {
          data: {
            id: [user, data.login, Math.floor(Math.random() * 10)].join(" "),
            source: user,
            target: data.login,
          },
        },
      ];
    });
  }

  function makeData(user, datum, cnt) {
    if (cnt < 3) {
      if (datum.length > 0) {
        datum.forEach((data) => {
          if (!isAlreayExistedUser(data.login)) {
            saveNode(user, data);
            saveEdge(user, data);
            makeMindMap(data.login, cnt);
          } else {
            saveEdge(user, data);
          }
        });
      }
    }
  }

  useEffect(() => {
    makeMindMap(user, 0);
  }, [user]);

  useEffect(() => {
    const cy = cytoscape({
      container: cytoRef.current,
      elements: mindMap,
      style: [
        // the stylesheet for the graph
        {
          selector: "node",
          style: {
            "background-color": "#666",
            label: "data(id)",
          },
        },
        {
          selector: "edge",
          style: {
            width: 2,
            "curve-style": "bezier",
            "line-color": "#ccc",
            "target-arrow-fill": "filled",
            "target-arrow-color": "#ccc",
            "target-arrow-shape": "vee",
          },
        },
      ],
      layout: {
        name: "cose-bilkent",
        animate: false,
        gravityRangeCompound: 10000,
        idealEdgeLength: 150,
        fit: true,
        tile: true,
      },
    });
    cy.on("tap", function (e) {
      const url = e.target.data("url");
      if (url && url !== "") {
        window.open(url);
      }
    });
    cy.on("tapstart mouseover", "node", function (e) {
      e.target.style("background-color", "steelblue");

      e.target._private.edges.forEach((edge) => {
        edge.style("line-color", "skyblue");
        edge.style("target-arrow-color", "skyblue");
      });
      cy.on("tapend mouseout", "node", function (e) {
        e.target.style("background-color", "#666");

        e.target._private.edges.forEach((edge) => {
          edge.style("line-color", "#ccc");
          edge.style("target-arrow-color", "#ccc");
        });
      });
    });
  }, [mindMap]);

  return <div id="cy" ref={cytoRef}></div>;
}

export default GithubMindmap;
