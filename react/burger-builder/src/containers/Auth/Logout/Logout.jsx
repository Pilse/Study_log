import React, { useEffect } from "react";
import * as actions from "../../../store/actions/index";
import { Redirect } from "react-router-dom";
import { connect } from "react-redux";

function Logout(props) {
  useEffect(() => {
    props.onLogout();
  }, []);

  return <Redirect to="/" />;
}

const dispatchToProps = (dispatch) => {
  return {
    onLogout: () => dispatch(actions.logout()),
  };
};

export default connect(null, dispatchToProps)(Logout);
