import * as actionType from "./actions";

export const saveResult = (result) => {
  //const updatedResult = result * 2;
  return {
    type: actionType.STORE_RESULT,
    result,
  };
};
export const store_result = (result) => {
  return function (dispatch, getState) {
    setTimeout(() => {
      // const oldCounter = getState().ctr.counter;
      // console.log(oldCounter);
      dispatch(saveResult(result));
    }, 2000);
  };
};
export const delete_result = (id) => {
  return {
    type: actionType.DELETE_RESULT,
    id,
  };
};
