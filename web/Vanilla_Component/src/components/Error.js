import Component from "../../core/Component.js";

class Error extends Component {
  setup() {
    this.element = document.createElement("div");
    this.target.appendChild(this.element);
  }

  updated() {
    this.render();
  }
  template() {
    const { token } = this.props;
    return `
      <div>
        <h1>${token}</h1>
      </div>
    `;
  }
}

export default Error;
