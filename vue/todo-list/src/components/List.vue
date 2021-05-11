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
  border-left: 4px solid rebeccapurple;
  transform: scale(1.05);
}
li {
  list-style-type: none;
  padding: 1rem;
}
.list-container:hover button {
  opacity: 1;
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
  opacity: 0;
}
button:hover {
  background-color: red;
  color: white;
}
</style>