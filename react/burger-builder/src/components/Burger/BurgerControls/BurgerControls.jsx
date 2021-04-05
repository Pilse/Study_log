import React from "react";
import "./BurgerControls.css";
import BurgerControl from "./BurgerControl/BurgerControl";

const controls = [
  { label: "Salad", type: "salad" },
  { label: "Bacon", type: "bacon" },
  { label: "Cheese", type: "cheese" },
  { label: "Meat", type: "meat" },
];
function burgerControls(props) {
  return (
    <div className="BuildControls">
      <p>
        Current Price:<strong>{props.price.toFixed(2)}</strong>
      </p>
      {controls.map((ctrl) => (
        <BurgerControl
          key={ctrl.label}
          label={ctrl.label}
          added={() => {
            props.ingredientAdded(ctrl.type);
          }}
          deleted={() => {
            props.ingredientDeleted(ctrl.type);
          }}
          disabled={props.disabled[ctrl.type]}
        />
      ))}
      <button
        className="OrderButton"
        disabled={props.purchasable}
        onClick={props.ordered}
      >
        {props.isAuth ? "ORDER NOW" : "SIGN UP TO ORDER"}
      </button>
    </div>
  );
}

export default burgerControls;
