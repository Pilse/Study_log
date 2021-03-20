import React from "react";
import "./Burger.css";
import burgerIngredient from "./BurgerIngredient/BurgerIngredient";
import BurgerIngredient from "./BurgerIngredient/BurgerIngredient";

function burger(props) {
  let transformedIngredients = Object.keys(props.ingredients)
    .map((ingredient) => {
      return [...Array(props.ingredients[ingredient])].map((_, idx) => {
        return <BurgerIngredient key={ingredient + idx} type={ingredient} />;
      });
    })
    .reduce((arr, el) => {
      return arr.concat(el);
    }, []);

  if (transformedIngredients.length === 0) {
    transformedIngredients = <p>Please Start Adding Ingredients</p>;
  }
  return (
    <div className="Burger">
      <BurgerIngredient type="bread-top" />
      {transformedIngredients}
      <BurgerIngredient type="bread-bottom" />
    </div>
  );
}

export default burger;
