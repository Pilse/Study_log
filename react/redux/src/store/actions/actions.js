export const INCREMENT = "INCREMENT";
export const DECREMENT = "DECREMENT";
export const ADD = "ADD";
export const SUBTRACT = "SUBTRACT";
export const STORE_RESULT = "STORE_RESULT";
export const DELETE_RESULT = "DELETE_RESULT";

// Action creater
export const increment = () => {
  return {
    type: INCREMENT,
  };
};
export const decrement = () => {
  return {
    type: DECREMENT,
  };
};
export const add = () => {
  return {
    type: ADD,
    value: 5,
  };
};
export const subtract = () => {
  return {
    type: SUBTRACT,
    value: 5,
  };
};
export const saveResult = (result) => {
  return {
    type: STORE_RESULT,
    result,
  };
};
export const store_result = (result) => {
  return function (dispatch) {
    setTimeout(() => {
      dispatch(saveResult(result));
    }, 2000);
  };
};
export const delete_result = (id) => {
  return {
    type: DELETE_RESULT,
    id,
  };
};
