import React from "react";
import { Link, Route } from "react-router-dom";

import Users from "./containers/Users";
import asyncComponent from "./hoc/asyncCompnent";

const AsyncPizza = asyncComponent(() => {
  return import("./containers/Pizza.js");
});

function App() {
  return (
    <div>
      <div>
        <Link to="/">Users</Link>
        <Link to="/pizza">Pizza</Link>
      </div>
      <div>
        <Route path="/" exact component={Users}></Route>
        <Route path="/pizza" component={AsyncPizza}></Route>
      </div>
    </div>
  );
}

export default App;
