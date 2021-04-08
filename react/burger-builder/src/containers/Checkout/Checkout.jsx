import { useHistory } from "react-router";
import CheckoutSummary from "../../components/Order/CheckoutSummary/CheckoutSummary";
import { Route, Redirect } from "react-router-dom";
import ContactData from "./ContactData/ContactData";
import { connect } from "react-redux";

function Checkout(props) {
  // const [ingredients, setIngredinets] = useState({
  //   salad: 0,
  //   meat: 0,
  //   cheese: 0,
  //   bacon: 0,
  // });
  // const [totalPrice, setTotalPrice] = useState("");
  const history = useHistory();
  //const location = useLocation();
  function checkoutCancelledHandler() {
    history.goBack();
  }
  function checkoutContinuedHandler() {
    history.replace("/checkout/contact-data");
  }

  // useEffect(() => {
  //   const query = new URLSearchParams(location.search);
  //   const updatedIngredients = {};
  //   let price = 0;
  //   for (let param of query.entries()) {
  //     if (param[0] === "price") {
  //       price = param[1];
  //     } else {
  //       updatedIngredients[param[0]] = +param[1];
  //     }
  //   }
  //   setIngredinets(updatedIngredients);
  //   setTotalPrice(price);
  // }, []);

  if (!props.ings || props.purchased) {
    return <Redirect to="/" />;
  }

  return (
    <div>
      <CheckoutSummary
        ingredients={props.ings}
        checkoutCancelled={checkoutCancelledHandler}
        checkoutContinued={checkoutContinuedHandler}
      />
      <Route path="/checkout/contact-data" component={ContactData} />
    </div>
  );
}

const stateToProps = (state) => {
  return {
    ings: state.burgerBuilder.ingredients,
    totalPrice: state.burgerBuilder.totalPrice,
    purchased: state.order.purchased,
  };
};

export default connect(stateToProps, null)(Checkout);
