import React, { useEffect } from "react";
import { Redirect, Route, Switch } from "react-router-dom";
import Layout from "./components/Layout/Layout";
import BurgerBuilder from "./containers/BurgerBuilder/BurgerBuilder";
import Logout from "./containers/Auth/Logout/Logout";
import { connect } from "react-redux";
import * as actions from "./store/actions/index";
import asyncComponent from "./hoc/asyncCompnent";

function App(props) {
  useEffect(() => {
    props.onTryAutoSignUp();
  });

  const asyncCheckout = asyncComponent(() => {
    return import("./containers/Checkout/Checkout");
  });

  const asyncOrders = asyncComponent(() => {
    return import("./containers/Orders/Orders");
  });

  const asyncAuth = asyncComponent(() => {
    return import("./containers/Auth/Auth");
  });

  let routes = (
    <Switch>
      <Route path="/auth" component={asyncAuth} />
      <Route path="/" exact component={BurgerBuilder} />
      <Redirect to="/" />
    </Switch>
  );
  if (props.isAuthenticated) {
    routes = (
      <Switch>
        <Route path="/checkout" component={asyncCheckout} />
        <Route path="/orders" component={asyncOrders} />
        <Route path="/auth" component={asyncAuth} />
        <Route path="/logout" component={Logout} />
        <Route path="/" exact component={BurgerBuilder} />
        <Redirect to="/" />
      </Switch>
    );
  }
  return <Layout>{routes}</Layout>;
}

const stateToProps = (state) => {
  return {
    isAuthenticated: state.auth.token !== null,
  };
};

const dispatchToProps = (dispatch) => {
  return {
    onTryAutoSignUp: () => dispatch(actions.authCheckState()),
  };
};

export default connect(stateToProps, dispatchToProps)(App);
