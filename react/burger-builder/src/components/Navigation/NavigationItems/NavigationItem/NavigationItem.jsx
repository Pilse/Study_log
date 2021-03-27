import React from "react";
import "./NavigationItem.css";
import { NavLink } from "react-router-dom";

function navigationItem(props) {
  return (
    <li className="NavigationItem">
      <NavLink to={props.link} exact>
        {props.children}
      </NavLink>
    </li>
  );
}

export default navigationItem;
