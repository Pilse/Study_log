import React, { useEffect, useState } from 'react';

function App() {

    const [data, Setdata] = useState([]);

    useEffect(() => {
        fetch('http://localhost:3002/api')
            .then(res => res.json())
            .then(data => Setdata(data));
    })
    


    return <div> {data.map(data =>  <h1>{data.hi}</h1>)} </div>
}

export default App;
