let currentCallback = null;

export const compute = (fn) => {
  currentCallback = fn;
  fn();
  currentCallback = null;
};

export const watch = (obj) => {
  const watchers = Object.keys(obj).reduce((map, key) => {
    map[key] = new Set();
    return map;
  }, new Map());

  return new Proxy(obj, {
    get: (target, name) => {
      if (currentCallback) watchers[name].add(currentCallback);
      return target[name];
    },

    set: (target, name, value) => {
      target[name] = value;
      watchers[name].forEach((cb) => cb());
      return true;
    },
  });
};
