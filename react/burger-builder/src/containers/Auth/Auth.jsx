import React, { useEffect, useState } from "react";
import Input from "../../components/UI/Input/Input";
import Button from "../../components/UI/Button/Button";
import "./Auth.css";
import * as actions from "../../store/actions/index";
import { connect } from "react-redux";
import Spinner from "../../components/UI/Spinner/Spinner";
import { Redirect } from "react-router-dom";

function Auth(props) {
  const [controls, setControls] = useState({
    email: "",
    password: "",
  });
  const [isSignedUp, setIsSignedUp] = useState(true);
  let errorMessage = "";

  useEffect(() => {
    if (!props.buildingBurger && props.authRedirectPath !== "/") {
      props.onSetRedirctPath();
    }
  }, []);

  function submitHandler(e) {
    e.preventDefault();
    props.onAuth(controls.email, controls.password, isSignedUp);
  }

  function changeHandler(e) {
    const { value, name } = e.target;
    setControls({
      ...controls,
      [name]: value,
    });
  }
  function switchAuthModeHandler() {
    setIsSignedUp((prevState) => !prevState);
  }
  if (props.loading) {
    return <Spinner />;
  }
  if (props.error) {
    errorMessage = (
      <p
        style={{
          borderLeft: "solid 6px red",
          color: "gray",
          backgroundColor: "#eee",
        }}
      >
        {props.error.message}
      </p>
    );
  }
  if (props.isAuthenticated) {
    return <Redirect to={props.authRedirectPath} />;
  }

  return (
    <div className="Auth">
      {errorMessage}
      <form onSubmit={submitHandler}>
        <Input
          inputtype="email"
          name="email"
          placeholder="Email"
          change={changeHandler}
        />
        <Input
          inputtype="password"
          name="password"
          placeholder="Password"
          change={changeHandler}
        />

        <Button btnType="Success">Submit</Button>
      </form>
      <Button clicked={switchAuthModeHandler} btnType="Danger">
        Sign {isSignedUp ? "In" : "Up"}
      </Button>
    </div>
  );
}

const stateToProps = (state) => {
  return {
    loading: state.auth.loading,
    error: state.auth.error,
    isAuthenticated: state.auth.token !== null,
    buildingBurger: state.burgerBuilder.building,
    authRedirectPath: state.auth.authRedirectPath,
  };
};

const dispatchToProps = (dispatch) => {
  return {
    onAuth: (email, password, isSignedUp) =>
      dispatch(actions.auth(email, password, isSignedUp)),
    onSetRedirctPath: () => dispatch(actions.SetAuthRedirectPath("/")),
  };
};

export default connect(stateToProps, dispatchToProps)(Auth);
