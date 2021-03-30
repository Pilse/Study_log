import * as actionTypes from "../actions/actions";

const initialState = {
  results: [],
};

const reducer = (state = initialState, action) => {
  switch (action.type) {
    case actionTypes.STORE_RESULT:
      return {
        ...state,
        results: state.results.concat({
          id: Math.random() * 10000,
          value: action.result,
        }),
      };
    case actionTypes.DELETE_RESULT:
      return {
        ...state,
        results: state.results.filter((result) => result.id !== action.id),
      };
    default:
      return state;
  }
};

export default reducer;
