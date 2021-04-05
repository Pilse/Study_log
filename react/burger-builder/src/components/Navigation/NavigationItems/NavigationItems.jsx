import React from "react";
import "./NavigationItems.css";
import NavigationItem from "../NavigationItems/NavigationItem/NavigationItem";

function navigationItems(props) {
  return (
    <ul className="NavigationItems">
      <NavigationItem link="/">Burger Builder</NavigationItem>
      {props.isAuthenticated ? (
        <NavigationItem link="/orders">Orders</NavigationItem>
      ) : null}
      {!props.isAuthenticated ? (
        <NavigationItem link="/auth">Login</NavigationItem>
      ) : (
        <NavigationItem link="/logout">Logout</NavigationItem>
      )}
    </ul>
  );
}

export default navigationItems;
