import * as actionTypes from "./actions";

const URL = "https://react-my-burger-9e521-default-rtdb.firebaseio.com";

export const purchaseBurgerSuccess = (id, orderData) => {
  return {
    type: actionTypes.PURCHASE_BURGER_SUCCESS,
    orderId: id,
    orderData: orderData,
  };
};

export const purchaseBurgerFail = (error) => {
  return {
    type: actionTypes.PURCHASE_BURGER_FAIL,
    error,
  };
};

export const purchaseBurgerStart = () => {
  return {
    type: actionTypes.PURCHASE_BURGER_START,
  };
};

export const purchaseBurger = (orderData) => {
  return async (dispatch) => {
    try {
      dispatch(purchaseBurgerStart());
      const res = await fetch(URL + "/orders.json", {
        method: "POST",
        headers: {
          "Content-Type": "Application/json",
        },
        body: JSON.stringify(orderData),
      });
      const data = await res.json();
      dispatch(purchaseBurgerSuccess(data.name, orderData));
    } catch (err) {
      dispatch(purchaseBurgerFail(err));
    }
  };
};

export const purchaseInit = () => {
  return {
    type: actionTypes.PURCHASE_INIT,
  };
};

export const fetchOrdersSuccess = (orders) => {
  return {
    type: actionTypes.FETCH_ORDERS_SUCCESS,
    orders,
  };
};

export const fetchOrdersFail = (error) => {
  return {
    type: actionTypes.FETCH_ORDERS_FAIL,
    error,
  };
};

export const fetchOrdersStart = () => {
  return {
    type: actionTypes.FETCH_ORDERS_START,
  };
};

export const fetchOrders = () => {
  return async (dispatch) => {
    dispatch(fetchOrdersStart());
    try {
      const res = await fetch(URL + "/orders.json");
      const data = await res.json();
      const fetchedOrders = [];
      for (let key in data) {
        fetchedOrders.push({
          ...data[key],
          id: key,
        });
      }
      dispatch(fetchOrdersSuccess(fetchedOrders));
    } catch (err) {
      dispatch(fetchOrdersFail(err));
    }
  };
};
