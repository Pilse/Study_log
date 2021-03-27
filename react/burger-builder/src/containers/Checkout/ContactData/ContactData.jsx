import React, { useState } from "react";
import { useHistory } from "react-router";
import Button from "../../../components/UI/Button/Button";
import Spinner from "../../../components/UI/Spinner/Spinner";
import "./ContactData.css";
import Input from "../../../components/UI/Input/Input";

const URL = "https://react-my-burger-9e521-default-rtdb.firebaseio.com";

function ContactData(props) {
  const initialState = {
    name: "",
    street: "",
    zipCode: "",
    country: "",
    email: "",
    deliveryMethod: "Fastest",
  };
  const [order, setOrder] = useState(initialState);
  const [loading, setLoading] = useState(false);
  const history = useHistory();

  async function orderHandler(e) {
    e.preventDefault();
    setLoading(true);
    const sumittedOrder = {
      ingredients: props.ingredients,
      price: props.price,
      customer: {
        name: order.name,
        address: {
          street: order.street,
          zipCode: order.zipCode,
          country: order.country,
        },
        email: order.country,
      },
      deliveryMethod: "fastest",
    };
    try {
      const res = await fetch(URL + "/orders.json", {
        method: "POST",
        body: JSON.stringify(sumittedOrder),
        headers: {
          "Content-Type": "application/json",
        },
      });
      const data = await res.json();
      setLoading(false);
      setOrder(initialState);
      history.push("/");
    } catch (err) {
      setLoading(false);
      console.log(err);
    }
  }

  function changeHandler(e) {
    const { value, name } = e.target;
    setOrder({
      ...order,
      [name]: value,
    });
  }

  const options = [
    <option key="fastest" value="fastest">
      Fastest
    </option>,
    <option key="cheapest" value="cheapest">
      Cheapest
    </option>,
  ];

  let form = (
    <form onSubmit={orderHandler}>
      <Input
        inputtype="text"
        name="name"
        placeholder="Name"
        change={changeHandler}
      />
      <Input
        inputtype="text"
        name="street"
        placeholder="Street"
        change={changeHandler}
      />
      <Input
        inputtype="text"
        name="zipCode"
        placeholder="ZIP Code"
        change={changeHandler}
      />
      <Input
        inputtype="text"
        name="country"
        placeholder="Country"
        change={changeHandler}
      />
      <Input
        inputtype="email"
        name="email"
        placeholder="Email"
        change={changeHandler}
      />
      <Input
        inputtype="select"
        options={options}
        name="deliveryMethod"
        change={changeHandler}
      />
      <Button btnType="Success" clicked={orderHandler}>
        ORDER
      </Button>
    </form>
  );
  if (loading) {
    form = <Spinner />;
  }

  return (
    <div className="ContactData">
      <h3>Enter Your Contact Data</h3>
      {form}
    </div>
  );
}

export default ContactData;
