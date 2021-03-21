import React, { useEffect, useState } from "react";
import Burger from "../../components/Burger/Burger";
import BurgerControlls from "../../components/Burger/BurgerControls/BurgerControls";
import Modal from "../../components/UI/Modal/Modal";
import OrderSummary from "../../components/Burger/OrderSummary/OrderSummary";
import Spinner from "../../components/UI/Spinner/Spinner";

const INGREDIENT_PRICES = {
  salad: 0.5,
  cheese: 0.4,
  meat: 1.3,
  bacon: 0.7,
};

const URL = "https://react-my-burger-9e521-default-rtdb.firebaseio.com";

function BurgerBuilder() {
  const [ingredients, setIngredients] = useState({
    salad: 0,
    bacon: 0,
    cheese: 0,
    meat: 0,
  });

  useEffect(async () => {
    const res = await fetch(URL + "/ingredients.json");
    const data = await res.json();
    setIngredients(data);
  }, []);
  const [totalPrice, setTotalPrice] = useState(4);
  const [purchasable, setPurchasable] = useState(true);
  const [purchasing, setPurchasing] = useState(false);
  const [loading, setLoading] = useState(false);

  function addIngredinetHandler(type) {
    const oldCount = ingredients[type];
    const updatedCount = oldCount + 1;
    const updatedIngredients = {
      ...ingredients,
    };
    updatedIngredients[type] = updatedCount;
    const priceAddtion = INGREDIENT_PRICES[type];
    const oldPrice = totalPrice;
    const newPrice = oldPrice + priceAddtion;
    setTotalPrice(newPrice);
    setIngredients(updatedIngredients);
    setPurchasable(newPrice === 4);
  }

  function deleteIngredientHandler(type) {
    let updatedIngredientNum = ingredients[type] - 1;
    if (updatedIngredientNum < 0) {
      updatedIngredientNum = 0;
    }
    const updatedIngredients = {
      ...ingredients,
    };
    updatedIngredients[type] = updatedIngredientNum;
    const updatedPrice = totalPrice - INGREDIENT_PRICES[type];
    setTotalPrice(updatedPrice);
    setIngredients(updatedIngredients);
    setPurchasable(updatedPrice === 4);
  }
  function purchaseHandler() {
    setPurchasing(true);
  }
  function purchaseCancleHandler() {
    setPurchasing(false);
  }
  async function purchaseContinueHandler() {
    //alert('You continue');
    setLoading(true);
    const order = {
      ingredients,
      price: totalPrice,
      customer: {
        name: "pilse Lee",
        address: {
          street: "Street 1",
          zipCode: "12345",
          country: "Korea",
        },
        email: "test@test.com",
      },
      deliveryMethod: "fastest",
    };
    try {
      const res = await fetch(URL + "/orders.json", {
        method: "POST",
        body: JSON.stringify(order),
        headers: {
          "Content-Type": "application/json",
        },
      });
      const data = await res.json();
      setLoading(false);
      setPurchasing(false);
    } catch (err) {
      setLoading(false);
      setPurchasing(false);
      console.log(err);
    }
  }

  const disabledInfo = {
    ...ingredients,
  };

  for (let key in disabledInfo) {
    disabledInfo[key] = disabledInfo[key] <= 0;
  }

  let orderSummary = (
    <OrderSummary
      ingredients={ingredients}
      purchaseCancled={purchaseCancleHandler}
      purchaseContinued={purchaseContinueHandler}
      price={totalPrice}
    />
  );
  if (loading) {
    orderSummary = <Spinner />;
  }

  return (
    <>
      <Modal
        show={purchasing}
        loading={loading}
        modalClosed={purchaseCancleHandler}
      >
        {orderSummary}
      </Modal>
      <Burger ingredients={ingredients} />
      <BurgerControlls
        ingredientAdded={addIngredinetHandler}
        ingredientDeleted={deleteIngredientHandler}
        disabled={disabledInfo}
        price={totalPrice}
        ordered={purchaseHandler}
        purchasable={purchasable}
      />
    </>
  );
}

export default BurgerBuilder;
