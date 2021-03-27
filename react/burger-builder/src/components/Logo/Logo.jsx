import React from "react";
import burgerLogo from "../../assets/image/burger-logo.png";
import { Link } from "react-router-dom";
import "./Logo.css";

function logo(props) {
  return (
    <div className="Logo" style={{ height: props.height }}>
      <Link to="/">
        <img src={burgerLogo} alt="myBurger" />
      </Link>
    </div>
  );
}

export default logo;
