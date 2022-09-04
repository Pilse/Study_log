import { useState } from "react";
import "./App.css";

export function replaceCamelWithSpaces(colorName) {
  return colorName.replace(/\B([A-Z])\B/g, " $1");
}

function App() {
  const [buttonColor, setButtonColor] = useState("MediumVioletRed");
  const [disabled, setDisabled] = useState(false);
  const newButttonColor =
    buttonColor === "MediumVioletRed" ? "MidnightBlue" : "MediumVioletRed";

  return (
    <div>
      <button
        style={{ backgroundColor: disabled ? "gray" : buttonColor }}
        disabled={disabled}
        onClick={() => setButtonColor(newButttonColor)}
      >
        Change to {newButttonColor}
      </button>

      <input
        id="disable-button-checkbox"
        type="checkbox"
        onChange={(e) => setDisabled(e.target.checked)}
      />

      <label htmlFor="disable-button-checkbox">Disable button</label>
    </div>
  );
}

export default App;
