import * as actionTypes from "./actions";
import { KEY } from "../../APIKEY";

export const authStart = () => {
  return {
    type: actionTypes.AUTH_START,
  };
};

export const authSuccess = (idToken, userId) => {
  return {
    type: actionTypes.AUTH_SUCCESS,
    idToken,
    userId,
  };
};

export const authFail = (error) => {
  return {
    type: actionTypes.AUTH_FAIL,
    error,
  };
};

export const logout = () => {
  return {
    type: actionTypes.AUTH_LOGOUT,
  };
};

export const checkAuthTimeout = (expirationTime) => {
  return (dispatch) => {
    setTimeout(() => {
      dispatch(logout());
    }, expirationTime * 1000);
  };
};

export const auth = (email, password, isSignedUp) => {
  let URL = `https://identitytoolkit.googleapis.com/v1/accounts:signUp?key=${KEY}`;
  if (!isSignedUp) {
    URL = `https://identitytoolkit.googleapis.com/v1/accounts:signInWithPassword?key=${KEY}`;
  }

  return async (dispatch) => {
    dispatch(authStart());
    const authData = {
      email,
      password,
      returnSecureToken: true,
    };
    try {
      const res = await fetch(URL, {
        method: "POST",
        headers: {
          "Content-Type": "application/json",
        },
        body: JSON.stringify(authData),
      });
      const data = await res.json();
      console.log(data);
      if (data.error) {
        dispatch(authFail(data.error));
      } else {
        dispatch(authSuccess(data.idToken, data.localId));
        dispatch(checkAuthTimeout(data.expiresIn));
      }
    } catch (err) {
      console.log(err);
      dispatch(authFail(err));
    }
  };
};

export const SetAuthRedirectPath = (path) => {
  return {
    type: actionTypes.SET_AUTH_REDIRECT_PATH,
    path,
  };
};
