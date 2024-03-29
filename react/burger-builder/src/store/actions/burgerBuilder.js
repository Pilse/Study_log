import * as actionTypes from "./actions";

export const addIngredient = (name) => {
  return {
    type: actionTypes.ADD_INGREDIENT,
    ingredientName: name,
  };
};

export const removeIngredient = (name) => {
  return {
    type: actionTypes.REMOVE_INGREDIENT,
    ingredientName: name,
  };
};

export const setIngredients = (ingredients) => {
  return {
    type: actionTypes.SET_INGREDIENTS,
    ingredients,
  };
};

export const fetchIngredientsFailed = () => {
  return {
    type: actionTypes.FETCH_INGREDIENTS_FAILED,
  };
};

export const initIngredients = () => {
  // return async (dispatch) => {
  //   try {
  //     const res = await fetch(URL + "/ingredients.json");
  //     const data = await res.json();
  //     dispatch(setIngredients(data));
  //   } catch (err) {
  //     dispatch(fetchIngredientsFailed());
  //   }
  // };
  return {
    type: actionTypes.INIT_INGREDIENTS,
  };
};
