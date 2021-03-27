import React, { useEffect, useState } from "react";
import Order from "../../components/Order/Order";

const URL = "https://react-my-burger-9e521-default-rtdb.firebaseio.com";

function Orders(props) {
  const [orders, setOrders] = useState([]);
  const [loading, setLoading] = useState(true);

  useEffect(async () => {
    try {
      const res = await fetch(URL + "/orders.json");
      const data = await res.json();
      const fetchedOrders = [];
      for (let key in data) {
        console.log(data);
        fetchedOrders.push({
          ...data[key],
          id: key,
        });
      }
      setOrders(fetchedOrders);
      setLoading(false);
    } catch (err) {
      setLoading(false);
      console.log(err);
    }
  }, []);

  return (
    <div>
      {orders.map((order) => (
        <Order
          key={order.id}
          ingredients={order.ingredients}
          price={+order.price}
        />
      ))}
    </div>
  );
}

export default Orders;
