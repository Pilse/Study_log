import Component from "../../core/Component.js";
import Error from "./Error.js";
import Lists from "./Lists.js";

import useRoute from "../hooks/useRoute.js";

class App extends Component {
  setup() {
    this.route = useRoute();

    this.state = {
      items: ["item1", "item2"],
    };
  }

  template() {
    return `
      <template id="template">
        <div id="app"></div>
      </template>
    `;
  }

  mounted() {
    this.onRouteChange();

    window.addEventListener("popstate", this.onRouteChange.bind(this));
  }

  updated() {
    this.onRouteChange();
  }

  onRouteChange() {
    switch (this.route.path()) {
      case "/":
        document
          .querySelector("body")
          .appendChild(document.getElementById("template").content);
        new Lists(document.getElementById("app"), {
          items: this.state.items,
          onAdd: this.addItems.bind(this),
        });
        break;

      case "/error":
        document
          .querySelector("body")
          .appendChild(document.getElementById("template").content);
        new Error(document.getElementById("app"), { items: this.state.items });
        break;

      default:
        document
          .querySelector("body")
          .appendChild(document.getElementById("template").content);
        new Error(document.getElementById("app"), { items: this.state.items });
        break;
    }
  }

  addItems() {
    this.setState({ items: [...this.state.items, "newitem"] });
  }
}

export default App;
