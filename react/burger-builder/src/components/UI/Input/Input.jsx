import React from "react";
import "./Input.css";

function Input(props) {
  let inputElement = null;

  switch (props.inputtype) {
    case "input":
      inputElement = (
        <input
          className="InputElement"
          onChange={props.change}
          type={props.inputtype}
          name={props.name}
          placeholder={props.placeholder}
        />
      );
      break;
    case "textarea":
      inputElement = (
        <textarea
          className="InputElement"
          onChange={props.change}
          type={props.inputtype}
          name={props.name}
          placeholder={props.placeholder}
        />
      );
      break;
    case "select":
      inputElement = (
        <select
          className="InputElement"
          name={props.name}
          onChange={props.change}
        >
          {props.options}
        </select>
      );
      break;
    default:
      inputElement = (
        <input
          className="InputElement"
          onChange={props.change}
          type={props.inputtype}
          name={props.name}
          placeholder={props.placeholder}
        />
      );
  }

  return <div className="Input">{inputElement}</div>;
}

export default Input;
