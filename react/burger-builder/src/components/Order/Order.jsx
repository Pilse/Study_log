import React from "react";
import "./Order.css";

function Order(props) {
  const ingredients = [];

  for (let ingredientName in props.ingredients) {
    ingredients.push({
      name: ingredientName,
      amount: props.ingredients[ingredientName],
    });
  }

  const ingredientOutput = ingredients.map((ig) => {
    return (
      <span
        key={ig.name}
        style={{
          textTransform: "capitalize",
          display: "inline-block",
          margin: "2px 8px",
          border: "1px solid #ccc",
          padding: "5px",
          minWidth: "96px",
          textAlign: "center",
        }}
      >
        {ig.name} ({ig.amount})
      </span>
    );
  });

  return (
    <div className="Order">
      <p>
        <strong> Ingredients:</strong>
      </p>
      <p>{ingredientOutput}</p>
      <p>
        Price: <strong>USD {props.price.toFixed(2)}</strong>
      </p>
    </div>
  );
}

export default Order;
