import React, { useState } from "react";
import "./Layout.css";
import Toolbar from "../Navigation/Toolbar/Toolbar";
import SideDrawer from "../Navigation/SideDrawer/SideDrawer";
import { connect } from "react-redux";

function Layout(props) {
  const [showSideDrawer, setShowSideDrawer] = useState(false);

  function sideDrawerClosedHandler() {
    setShowSideDrawer(false);
  }

  return (
    <>
      <Toolbar
        isAuth={props.isAuthenticated}
        showSideDrawer={() => setShowSideDrawer((prevValue) => !prevValue)}
      />
      <SideDrawer
        isAuth={props.isAuthenticated}
        open={showSideDrawer}
        closed={sideDrawerClosedHandler}
      />
      <main className="Content">{props.children}</main>
    </>
  );
}

const stateToProps = (state) => {
  return {
    isAuthenticated: state.auth.token !== null,
  };
};

export default connect(stateToProps)(Layout);
