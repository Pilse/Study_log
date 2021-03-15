import React, { useEffect, useRef } from 'react';
import './GithubMindmap.css';
import cytoscape from 'cytoscape';

const APIURL = 'https://api.github.com/users/';

function GithubMindmap() {

  const cytoRef = useRef();


  useEffect(() => {
   
    const cy = cytoscape({
      container: cytoRef.current,
      elements: [ // list of graph elements to start with
        { // node a
            "data": { "id": 'a' }
        },
        { // node b
            "data": { "id": 'b' }
        },
        { // edge ab
            "data": { "id": 'ab', "source": 'a', "target": 'b' }
        }
    ],

    style: [ // the stylesheet for the graph
        {
            selector: 'node',
            style: {
                'background-color': '#666',
                'label': 'data(id)'
            }
        },

        {
            selector: 'edge',
            style: {
                'width': 3,
                'line-color': '#ccc',
                'target-arrow-color': '#ccc',
                'target-arrow-shape': 'triangle'
            }
        }
    ],

    layout: {
        name: 'grid',
        rows: 5
    }
    });
  }, []);


  return (
    <div id='cy' ref={cytoRef}></div>
  );
}
export async function makeMindMap(userName) {
  const res = await fetch(APIURL + userName + '/followers');
  const data = await res.json();
  const name = data.map(data => data.login);
  console.log(name);
}

export default GithubMindmap;
