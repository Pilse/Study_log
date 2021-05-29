<template>
  <div>
    <div>
      <slot name="title" />
      <span><slot name="subtitle">subtitle</slot></span>
    </div>
    <hr />
    <div>
      <slot name="content" />
    </div>
  </div>
</template>

<script>
export default {
  name: "Quote",
  props: ["quote"],
};
</script>
<style scoped>
div {
  border: 1px solid #ccc;
  box-shadow: 1px 1px 2px black;
  padding: 30px;
  margin: 30px auto;
  text-align: center;
}
</style>