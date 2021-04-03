import React, { useEffect, useState } from "react";
import Order from "../../components/Order/Order";
import { connect } from "react-redux";
import Spinner from "../../components/UI/Spinner/Spinner";
import * as actions from "../../store/actions/index";

const URL = "https://react-my-burger-9e521-default-rtdb.firebaseio.com";

function Orders(props) {
  // const [orders, setOrders] = useState([]);
  // const [loading, setLoading] = useState(true);

  // useEffect(async () => {
  //   try {
  //     const res = await fetch(URL + "/orders.json");
  //     const data = await res.json();
  //     const fetchedOrders = [];
  //     for (let key in data) {
  //       console.log(data);
  //       fetchedOrders.push({
  //         ...data[key],
  //         id: key,
  //       });
  //     }
  //     setOrders(fetchedOrders);
  //     setLoading(false);
  //   } catch (err) {
  //     setLoading(false);
  //     console.log(err);
  //   }
  // }, []);
  useEffect(() => {
    props.onFetchOrders();
  }, []);
  if (props.loading) {
    return <Spinner />;
  }

  return (
    <div>
      {props.orders.map((order) => (
        <Order
          key={order.id}
          ingredients={order.ingredients}
          price={+order.price}
        />
      ))}
    </div>
  );
}

const stateToProps = (state) => {
  return {
    orders: state.order.orders,
    loading: state.order.loading,
  };
};

const dispatchToProps = (dispatch) => {
  return {
    onFetchOrders: () => dispatch(actions.fetchOrders()),
  };
};

export default connect(stateToProps, dispatchToProps)(Orders);
