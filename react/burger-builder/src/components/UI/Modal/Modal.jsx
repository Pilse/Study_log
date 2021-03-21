import React from "react";
import "./Modal.css";
import Backdrop from "../Backdrop/Backdrop";

const showIsEqual = (prevModal, nextModal) => {
  return (
    prevModal.show === nextModal.show && prevModal.loading === nextModal.loading
  );
};

function modal(props) {
  return (
    <>
      <Backdrop open={props.show} clicked={props.modalClosed} />
      <div
        className="Modal"
        style={{
          transform: props.show ? "translateY(0)" : "translateY(-100vh)",
          opacity: props.show ? "1" : "0",
        }}
      >
        {props.children}
      </div>
    </>
  );
}

export default React.memo(modal, showIsEqual);
