import React, { useEffect, useRef, useState } from 'react';
import './GithubMindmap.css';
import cytoscape from 'cytoscape';

const APIURL = 'https://api.github.com/users/';
let MAXCOUNT = 0;

function GithubMindmap({ user }) {

  const cytoRef = useRef();
  const [mindMap, setMindMap] = useState([
    {
      data: {
        id: user,
        label: user
      }
    }
  ]);

  async function makeMindMap(userName, cnt) {
    if(cnt==0){
      setMindMap([
        {
          data: {
            id: user,
            label: user
          }
        }
      ])
    }
    const res = await fetch(APIURL + userName + '/followers');
    const data = await res.json();
    console.log(data);

    makeData(userName, data, cnt+1);

  }

  function isAlreayExistedUser(userName) {
    mindMap.forEach(node => {
      if (node.data.id === userName) {
        return true;
      }
    });
    return false;
  }

  function saveData(user, data) {
    setMindMap((prevData) => {
      return [
        ...prevData,
        {
          data: {
            id: data.login,
            url: data.home_url,
            label: data.login
          }
        },
        {
          data: {
            id: data.login,
            source: user,
            target: data.login
          }
        }
      ]
    })
  }


  function makeData(user, datum, cnt) {
    if (cnt < 2) {
      if (datum.length > 0) {
        datum.forEach(data => {
          if (!isAlreayExistedUser(data.login)) {
            saveData(user, data);
            
          }
        })
      }
    }
  }

  useEffect(() => {

    makeMindMap(user, 0);

    const cy = cytoscape({
      container: cytoRef.current,
      elements: mindMap,
      style: [ // the stylesheet for the graph
        {
          selector: 'node',
          style: {
            'background-color': '#111',
            'label': 'data(id)'
          }
        },
        {
          selector: 'edge',
          style: {
            'width': 3,
            'line-color': '#111',
            'target-arrow-color': '#111',
            'target-arrow-shape': 'triangle'
          }
        }
      ],
      layout: {
        name: 'grid',
        rows: 5
      }
    });
  }, [user]);


  return (
    <div id='cy' ref={cytoRef}></div>
  );
}

export default GithubMindmap;
