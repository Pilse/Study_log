import React, { useState } from "react";

function App() {
  const [todolist, setTodolist] = useState({
    item: "",
    itemList: []
  });

  function handleChange(event) {
    const value = event.target.value; 
    setTodolist((prevValue) => {
      return {
        ...prevValue,
        item: value
      };
    });
  }

  function handleClick() {
    setTodolist((prevValue) => {
      return {
        itemList: [...prevValue.itemList, todolist.item],
        item: ""
      };
    });
  }

  return (
    <div className="container">
      <div className="heading">
        <h1>To-Do List</h1>
      </div>
      <div className="form">
        <input onChange={handleChange} type="text" value={todolist.item} />
        <button>
          <span onClick={handleClick}>Add</span>
        </button>
      </div>
      <div>
        <ul>
          {todolist.itemList.map((item) => {
            return <li>{item}</li>;
          })}
        </ul>
      </div>
    </div>
  );
}

export default App;
