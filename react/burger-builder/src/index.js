import React from "react";
import ReactDOM from "react-dom";
import App from "./App";
import { BrowserRouter } from "react-router-dom";
import "./index.css";
import { Provider } from "react-redux";
import { createStore } from "redux";
import burgerBuilderReducer from "./store/reducers/burgerBuilder";

const store = createStore(
  burgerBuilderReducer,
  window.__REDUX_DEVTOOLS_EXTENSION__()
);

const app = (
  <Provider store={store}>
    <BrowserRouter>
      <App />
    </BrowserRouter>
  </Provider>
);

ReactDOM.render(app, document.querySelector("#root"));
