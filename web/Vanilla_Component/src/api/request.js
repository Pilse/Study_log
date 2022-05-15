const request = async (url) => {
  try {
    const res = await fetch(url);

    if (res.ok) {
      const data = await res.json();

      return data;
    } else {
      throw new Error(res.status);
    }
  } catch (err) {
    console.log(err);
  }
};

export default request;

tableBodyContents = tableBodyHeaders.map((key) =>
  data.map((obj) => traverse(obj, key))
);

const transpose = (matrix) =>
  matrix.reduce(
    (prev, next) => next.map((item, i) => (prev[i] || []).concat(next[i])),
    []
  );
