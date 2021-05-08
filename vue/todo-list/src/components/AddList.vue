<template>
  <form @submit="handleSubmit">
    <input type="text" placeholder="Add New Item" v-model="text" name="text" />
    <input type="submit" value="+" />
  </form>
</template>

<script>
export default {
  name: "AddList",
  data() {
    return {
      text: "",
    };
  },
  methods: {
    handleSubmit(e) {
      e.preventDefault();
      if (this.text) {
        this.$emit("add-list", this.text);
      }
      this.text = "";
    },
  },
};
</script>

<style scoped>
form {
  display: flex;
  justify-content: space-between;
  align-items: center;
  margin: 2rem auto;
  width: 100%;
}
input[type="text"] {
  border: none;
  outline: none;
  background-color: transparent;
  border-bottom: 3px solid #907fa4;
  width: 90%;
  font-size: 24px;
  padding: 10px 0;
  transition: 0.3s ease-in-out;
}
input[type="text"]:focus {
  border-bottom: 3px solid rebeccapurple;
}
input[type="submit"] {
  font-size: 16px;
  border: none;
  width: 25px;
  height: 25px;
  border-radius: 50%;
  outline: none;
  background-color: #ededd0;
  cursor: pointer;
  color: rebeccapurple;
  transition: 0.2s ease;
}
input[type="submit"]:hover {
  background-color: rebeccapurple;
  color: white;
}
</style>