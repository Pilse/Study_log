import React, { useState } from "react";
import "./Layout.css";
import Toolbar from "../Navigation/Toolbar/Toolbar";
import SideDrawer from "../Navigation/SideDrawer/SideDrawer";

function Layout({ children }) {
  const [showSideDrawer, setShowSideDrawer] = useState(false);

  function sideDrawerClosedHandler() {
    setShowSideDrawer(false);
  }

  return (
    <>
      <Toolbar
        showSideDrawer={() => setShowSideDrawer((prevValue) => !prevValue)}
      />
      <SideDrawer open={showSideDrawer} closed={sideDrawerClosedHandler} />
      <main className="Content">{children}</main>
    </>
  );
}

export default Layout;
