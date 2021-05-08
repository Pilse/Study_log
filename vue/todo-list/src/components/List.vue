<template>
  <div class="list-container">
    <li>{{ list.list }}</li>
    <button @click="handleClick">x</button>
  </div>
</template>

<script>
export default {
  name: "List",
  props: {
    list: Object,
  },
  methods: {
    handleClick() {
      this.$emit("delete-list", this.list.id);
    },
  },
};
</script>

<style scoped>
.list-container {
  display: flex;
  justify-content: space-between;
  align-items: center;
  border-left: 4px solid #907fa4;
  box-shadow: 0 0 2px 2px rgba(0, 0, 0, 0.1);
  margin-bottom: 5px;
  transition: 0.2s ease;
}
.list-container:hover {
  background-color: #ddd;
}
li {
  list-style-type: none;
  padding: 1rem;
}
button {
  font-size: 14px;
  outline: none;
  border: none;
  color: red;
  background-color: transparent;
  padding: 20px 10px;
  cursor: pointer;
  transition: 0.2s ease;
}
button:hover {
  background-color: red;
  color: white;
}
</style>