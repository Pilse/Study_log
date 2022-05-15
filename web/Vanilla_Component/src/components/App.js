import Component from "../../core/Component.js";
import Error from "./Error.js";
import Lists from "./Lists.js";

import useRoute from "../hooks/useRoute.js";
import store from "../store.js";
import { compute } from "../../core/observe.js";

class App extends Component {
  initialState() {
    return {
      items: ["items1", "items2"],
    };
  }

  setup() {
    this.route = useRoute();
  }

  render() {
    // window.addEventListener("popstate", this.onRouteChange.bind(this));
    // this.onRouteChange();
    this.error = new Error(document.getElementById("app"), {
      token: store.state.token,
    });
    this.list = new Lists(document.getElementById("app"), {
      items: this.state.items,
      onAdd: this.addItems.bind(this),
    });

    compute(() => {
      this.error.updateProps({
        token: store.state.token,
      });
    });

    compute(() => {
      this.list.updateProps({
        items: this.state.items,
        onAdd: this.addItems.bind(this),
      });
    });
  }

  updated() {
    // this.onRouteChange();
    console.log(this.state.items);
  }

  onRouteChange() {
    switch (this.route.path()) {
      case "/":
        this.route.navigate("/list");
        break;

      case "/list":
        new Lists(document.getElementById("app"), {
          items: this.state.items,
          onAdd: this.addItems.bind(this),
        });
        break;

      case "/error":
        new Error(document.getElementById("app"), { items: this.state.items });
        break;

      default:
        this.route.navigate("/list");
        break;
    }
  }

  addItems() {
    console.log("additems");
    this.setState({ items: [...this.state.items, "newitem"] });
  }
}

export default App;
