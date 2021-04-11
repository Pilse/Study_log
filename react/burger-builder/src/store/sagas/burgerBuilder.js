import { put } from "redux-saga/effects";
import * as actions from "../actions";

const URL = "https://react-my-burger-9e521-default-rtdb.firebaseio.com";

export function* initIngredientsSaga(action) {
  try {
    const res = yield fetch(URL + "/ingredients.json");
    const data = yield res.json();
    yield put(actions.setIngredients(data));
  } catch (err) {
    yield put(actions.fetchIngredientsFailed());
  }
}
