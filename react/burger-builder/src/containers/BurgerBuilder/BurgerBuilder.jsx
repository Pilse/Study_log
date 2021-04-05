import React, { useEffect, useState } from "react";
import Burger from "../../components/Burger/Burger";
import BurgerControlls from "../../components/Burger/BurgerControls/BurgerControls";
import Modal from "../../components/UI/Modal/Modal";
import OrderSummary from "../../components/Burger/OrderSummary/OrderSummary";
import Spinner from "../../components/UI/Spinner/Spinner";
import { useHistory } from "react-router";
import { connect } from "react-redux";
import * as actions from "../../store/actions/index";
import { initIngredients } from "../../store/actions/burgerBuilder";

function BurgerBuilder(props) {
  // const [ingredients, setIngredients] = useState({
  //   salad: 0,
  //   bacon: 0,
  //   cheese: 0,
  //   meat: 0,
  // });

  useEffect(() => {
    props.onInitIngredients();
  }, []);

  //const [totalPrice, setTotalPrice] = useState(4);
  //const [purchasable, setPurchasable] = useState(true);
  const [loading, setLoading] = useState(false);
  const [purchasing, setPurchasing] = useState(false);
  const history = useHistory();

  // function addIngredinetHandler(type) {
  //   const oldCount = ingredients[type];
  //   const updatedCount = oldCount + 1;
  //   const updatedIngredients = {
  //     ...props.ings,
  //   };
  //   updatedIngredients[type] = updatedCount;
  //   const priceAddtion = INGREDIENT_PRICES[type];
  //   const oldPrice = totalPrice;
  //   const newPrice = oldPrice + priceAddtion;
  //   setTotalPrice(newPrice);
  //   setIngredients(updatedIngredients);
  //   setPurchasable(newPrice === 4);
  // }

  // function deleteIngredientHandler(type) {
  //   let updatedIngredientNum = ingredients[type] - 1;
  //   if (updatedIngredientNum < 0) {
  //     updatedIngredientNum = 0;
  //   }
  //   const updatedIngredients = {
  //     ...props.ings,
  //   };
  //   updatedIngredients[type] = updatedIngredientNum;
  //   const updatedPrice = totalPrice - INGREDIENT_PRICES[type];
  //   setTotalPrice(updatedPrice);
  //   setIngredients(updatedIngredients);
  //   setPurchasable(updatedPrice === 4);
  // }
  function purchaseHandler() {
    if (props.isAuthenticated) {
      setPurchasing(true);
    } else {
      props.onSetRedirectPath("/checkout");
      history.push("/auth");
    }
  }
  function purchaseCancleHandler() {
    setPurchasing(false);
  }
  async function purchaseContinueHandler() {
    //alert('You continue');
    // const queryParams = [];
    // for (let i in props.ings) {
    //   queryParams.push(
    //     encodeURIComponent(i) + "=" + encodeURIComponent(props.ing[i])
    //   );
    // }
    // queryParams.push("price=" + props.totalPrice);
    // const queryString = queryParams.join("&");
    props.onInitPurchase();
    history.push("/checkout");
  }

  const disabledInfo = {
    ...props.ings,
  };

  for (let key in disabledInfo) {
    disabledInfo[key] = disabledInfo[key] <= 0;
  }

  let orderSummary = (
    <OrderSummary
      ingredients={props.ings}
      purchaseCancled={purchaseCancleHandler}
      purchaseContinued={purchaseContinueHandler}
      price={props.totalPrice}
    />
  );
  if (!props.ings) {
    return <Spinner />;
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
      <Burger ingredients={props.ings} />
      <BurgerControlls
        ingredientAdded={props.onIngredientAdded}
        ingredientDeleted={props.onIngredientRemoved}
        disabled={disabledInfo}
        price={props.totalPrice}
        ordered={purchaseHandler}
        isAuth={props.isAuthenticated}
        purchasable={props.totalPrice === 4}
      />
    </>
  );
}
const stateToProps = (state) => {
  return {
    ings: state.burgerBuilder.ingredients,
    totalPrice: state.burgerBuilder.totalPrice,
    error: state.burgerBuilder.error,
    isAuthenticated: state.auth.token !== null,
    buildingBurger: state.burgerBuilder.building,
    authRedirectPath: state.auth.authRedirectPath,
  };
};
const dispathToProps = (dispatch) => {
  return {
    onIngredientAdded: (ingredientName) => {
      dispatch(actions.addIngredient(ingredientName));
    },
    onIngredientRemoved: (ingredientName) => {
      dispatch(actions.removeIngredient(ingredientName));
    },
    onInitIngredients: () => dispatch(actions.initIngredients()),
    onInitPurchase: () => dispatch(actions.purchaseInit()),
    onSetRedirectPath: (path) => dispatch(actions.SetAuthRedirectPath(path)),
  };
};

export default connect(stateToProps, dispathToProps)(BurgerBuilder);
