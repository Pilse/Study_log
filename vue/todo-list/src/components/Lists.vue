<template>
  <div>
    <ul :key="list.id" v-for="list in lists">
      <List :list="list" @delete-list="$emit('delete-list', list.id)" />
    </ul>
  </div>
</template>

<script>
import List from "./List";

export default {
  name: "Lists",
  components: {
    List,
  },
  props: {
    lists: Array,
  },
  emits: ["delete-list"],
};
</script>