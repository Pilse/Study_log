import { watch } from "../core/observe.js";

const store = {
  state: watch({
    token: "agjiosdakvjnwiuo29-dhg",
  }),

  setState(newState) {
    for (const [key, value] of Object.entries(newState)) {
      this.state[key] = value;
    }
  },
};

export default store;
