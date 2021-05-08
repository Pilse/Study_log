<template>
  <div class="container">
    <Header />
    <AddList @add-List="addList" />
    <Lists :lists="lists" @delete-list="deleteList" />
  </div>
</template>

<script>
import Header from "./components/Header";
import Lists from "./components/Lists";
import AddList from "./components/AddList";

export default {
  name: "App",
  components: {
    Header,
    Lists,
    AddList,
  },
  data() {
    return {
      lists: [],
    };
  },
  methods: {
    addList(text) {
      const newList = {
        id: Math.floor(Math.random() * 100000),
        list: text,
      };
      this.lists = [...this.lists, newList];
    },
    deleteList(id) {
      this.lists = this.lists.filter((list) => list.id !== id);
    },
  },
};
</script>

<style>
* {
  box-sizing: border-box;
  margin: 0;
  padding: 0;
}
#app {
  display: flex;
  flex-direction: column;
  justify-content: center;
  align-items: center;
  text-align: center;
  padding: 3rem 0;
  background: linear-gradient(to right, #d4d3dd, #efefbb);
  max-width: 100vw;
  min-height: 100vh;
  overflow-x: hidden;
}
.container {
  width: 350px;
}
</style>
