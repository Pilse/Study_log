import Component from "../../core/Component.js";

class Lists extends Component {
  template() {
    const { items } = this.props;
    return `
      <div>
        <ul>
        ${items.map((item) => `<li>${item}</li>`).join("")}
        </ul>
        <button id="add">add</button>
      </div>
    `;
  }

  addEvent() {
    document.getElementById("add").addEventListener("click", () => {
      this.props.onAdd();
    });
  }
}

export default Lists;
