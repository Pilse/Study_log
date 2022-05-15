import Component from "../../core/Component.js";
import useRoute from "../hooks/useRoute.js";
import List from "./List.js";
import Loader from "./Loader.js";
import store from "../store.js";

class Lists extends Component {
  setup() {
    this.route = useRoute();
    this.element = document.createElement("div");
    this.target.appendChild(this.element);
  }

  template() {
    const { items } = this.props;
    return `
      <ul>
        ${items.map((item) => List(item)).join("")}
      </ul>
      <button id="add">add</button>
      <button id="error">error</button>
      <button id="newtoken">token</button>
      ${Loader()}

    `;
  }

  updated() {
    this.render();
  }

  addEvent() {
    document.getElementById("add").addEventListener("click", () => {
      this.props.onAdd();
    });
    document.getElementById("error").addEventListener("click", () => {
      this.route.navigate("/error");
    });
    document.getElementById("newtoken").addEventListener("click", () => {
      store.setState({ token: Math.random().toString() });
    });
  }
}

export default Lists;
