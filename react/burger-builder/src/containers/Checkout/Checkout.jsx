import React, { useEffect, useState } from "react";
import { useHistory, useLocation } from "react-router";
import CheckoutSummary from "../../components/Order/CheckoutSummary/CheckoutSummary";

function Checkout() {
  const [ingredients, setIngredinets] = useState({
    salad: 1,
    meat: 1,
    cheese: 1,
    bacon: 1,
  });
  const history = useHistory();
  const location = useLocation();
  function checkoutCancelledHandler() {
    history.goBack();
  }
  function checkoutContinuedHandler() {
    history.replace("/checkout/contact-data");
  }

  useEffect(() => {
    const query = new URLSearchParams(location.search);
    const updatedIngredients = {};
    for (let param of query.entries()) {
      console.log(param);
      updatedIngredients[param[0]] = +param[1];
    }
    setIngredinets(updatedIngredients);
  }, []);

  return (
    <div>
      <CheckoutSummary
        ingredients={ingredients}
        checkoutCancelled={checkoutCancelledHandler}
        checkoutContinued={checkoutContinuedHandler}
      />
    </div>
  );
}

export default Checkout;
