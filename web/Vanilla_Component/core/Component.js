class Component {
  target;
  state;
  props;

  constructor(target, props) {
    this.target = target;
    this.props = props;
    this.setup();
    this.render();
    this.mounted();
    this.addEvent();
  }

  setup() {}

  mounted() {}

  updated() {}

  template() {
    return ``;
  }

  render() {
    this.target.innerHTML = this.template();
  }

  setState(value) {
    this.state = { ...this.state, ...value };
    this.render();
    this.updated();
  }

  updateProps(value) {
    this.props = value;
    this.render();
    this.updated();
  }

  addEvent() {}
}

export default Component;
