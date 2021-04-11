import { put, delay } from "redux-saga/effects";
import * as actionTypes from "../actions/actions";
import * as actions from "../actions/index";
import { KEY } from "../../APIKEY";

export function* logoutSaga(action) {
  yield localStorage.removeItem("token");
  yield localStorage.removeItem("expirationDate");
  yield localStorage.removeItem("userId");
  yield put(actions.logoutSucced());
}

export function* checkAuthTimeoutSaga(action) {
  yield delay(action.expirationTime * 1000);
  yield put(actions.logout());
}

export function* authUserSaga(action) {
  let URL = `https://identitytoolkit.googleapis.com/v1/accounts:signUp?key=${KEY}`;
  if (!action.isSignedUp) {
    URL = `https://identitytoolkit.googleapis.com/v1/accounts:signInWithPassword?key=${KEY}`;
  }

  yield put(actions.authStart());
  const authData = {
    email: action.email,
    password: action.password,
    returnSecureToken: true,
  };
  try {
    const res = yield fetch(URL, {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify(authData),
    });
    const data = yield res.json();

    if (data.error) {
      put(actions.authFail(data.error));
    } else {
      const expirationDate = yield new Date(
        new Date().getTime() + data.expiresIn * 1000
      );
      yield localStorage.setItem("token", data.idToken);
      yield localStorage.setItem("expirationDate", expirationDate);
      yield localStorage.setItem("userId", data.localId);
      yield put(actions.authSuccess(data.idToken, data.localId));
      yield put(actions.checkAuthTimeout(data.expiresIn));
    }
  } catch (err) {
    yield put(actions.authFail(err));
  }
}

export function* authCheckStateSaga(action) {
  const token = yield localStorage.getItem("token");
  if (!token) {
    yield put(actions.logout());
  } else {
    const expirationDate = yield new Date(
      localStorage.getItem("expirationDate")
    );
    if (expirationDate > new Date()) {
      const userId = yield localStorage.getItem("userId");
      yield put(actions.authSuccess(token, userId));
      yield put(
        actions.checkAuthTimeout(
          (expirationDate.getTime() - new Date().getTime()) / 1000
        )
      );
    } else {
      yield put(actions.logout());
    }
  }
}
