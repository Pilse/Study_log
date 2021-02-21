import React, { useState } from 'react';

function Search ({setTerm}) {
    const [input,setInput] = useState('');

    function handleChange (event) {
        setInput(event.target.value);
    } 
    function handleSubmit (event) {
        event.preventDefault();
        setTerm(input);
        setInput('');
    }
    return(
        <div className="search">
            <form onSubmit={handleSubmit} action="">
                <input onChange={handleChange} type="text" placeholder="Search" value={input}/>
            </form>
        </div>
    )
}

export default Search;