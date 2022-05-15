import { watch } from "./observe.js";

class Component {
  target;
  state;
  props;
  element;

  constructor(target, props) {
    this.target = target;
    this.props = props;
    this.state = watch(this.initialState());

    this.setup();
    this.render();
    this.mounted();
  }

  setup() {}
  mounted() {}
  updated() {}

  initialState() {
    return {};
  }

  template() {
    return ``;
  }

  render() {
    if (this.element) {
      this.element.innerHTML = this.template();
    } else {
      this.target.innerHTML = this.template();
    }
    this.addEvent();
  }

  setState(newState) {
    Object.keys(newState).forEach((key) => {
      this.state[key] = newState[key];
    });
    this.updated();
  }

  updateProps(newProps) {
    this.props = newProps;
    this.updated();
  }
  addEvent() {}
}

export default Component;
