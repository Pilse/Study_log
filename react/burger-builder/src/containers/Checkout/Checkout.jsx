import React, { useEffect, useState } from "react";
import { useHistory, useLocation } from "react-router";
import CheckoutSummary from "../../components/Order/CheckoutSummary/CheckoutSummary";
import { Route } from "react-router-dom";
import ContactData from "./ContactData/ContactData";

function Checkout() {
  const [ingredients, setIngredinets] = useState({
    salad: 0,
    meat: 0,
    cheese: 0,
    bacon: 0,
  });
  const [totalPrice, setTotalPrice] = useState("");
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
    let price = 0;
    for (let param of query.entries()) {
      if (param[0] === "price") {
        price = param[1];
      } else {
        updatedIngredients[param[0]] = +param[1];
      }
    }
    setIngredinets(updatedIngredients);
    setTotalPrice(price);
  }, []);

  return (
    <div>
      <CheckoutSummary
        ingredients={ingredients}
        checkoutCancelled={checkoutCancelledHandler}
        checkoutContinued={checkoutContinuedHandler}
      />
      <Route
        path="/checkout/contact-data"
        render={() => {
          return <ContactData ingredients={ingredients} price={totalPrice} />;
        }}
      />
    </div>
  );
}

export default Checkout;
