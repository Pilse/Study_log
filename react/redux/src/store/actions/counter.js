import * as actionType from "./actions";

export const increment = () => {
  return {
    type: actionType.INCREMENT,
  };
};
export const decrement = () => {
  return {
    type: actionType.DECREMENT,
  };
};
export const add = () => {
  return {
    type: actionType.ADD,
    value: 5,
  };
};
export const subtract = () => {
  return {
    type: actionType.SUBTRACT,
    value: 5,
  };
};
