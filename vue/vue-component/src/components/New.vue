<template>
  <div>
    <h3>New Quote</h3>
    <button @click="counter++">plus</button>
    <p>{{ counter }}</p>
  </div>
</template>

<script>
export default {
  name: "Quote",
  props: ["quote"],
  data() {
    return {
      counter: 0,
    };
  },
  activated() {
    console.log("activated");
  },
  deactivated() {
    console.log("deactivated");
  },
};
</script>
<style scoped>
</style>