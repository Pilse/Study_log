import React from "react";
import "./Toolbar.css";
import Logo from "../../Logo/Logo";
import NavigationItems from "../NavigationItems/NavigationItems";

function toolbar(props) {
  return (
    <header className="Toolbar">
      <button className="MenuBtn" onClick={props.showSideDrawer}>
        ≡
      </button>
      <Logo />
      <nav className="DesktopOnly">
        <NavigationItems isAuthenticated={props.isAuth} />
      </nav>
    </header>
  );
}

export default toolbar;
