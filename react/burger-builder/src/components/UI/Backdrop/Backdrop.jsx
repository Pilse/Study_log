import React from "react";
import "./Backdrop.css";

function backdrop(props) {
  if (props.open) {
    return <div className="Backdrop" onClick={props.clicked}></div>;
  } else {
    return null;
  }
}

export default backdrop;
