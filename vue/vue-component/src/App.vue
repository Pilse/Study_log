<template>
  <div class="container">
    <div class="row">
      <div class="col">
        <button @click="selectedComponent = 'Quote'">Quote</button>
        <button @click="selectedComponent = 'Author'">Author</button>
        <button @click="selectedComponent = 'New'">New</button>
        <hr />
        <p>{{ selectedComponent }}</p>
        <keep-alive>
          <component :is="selectedComponent">
            <p>default</p>
          </component>
        </keep-alive>
        <!-- <Quote>
          <h2 slot="title">The Quote</h2>
          <p slot="content">A wonderful quote</p>
        </Quote> -->
      </div>
    </div>
  </div>
</template>

<script>
import Quote from "./components/Quote.vue";
import Author from "./components/Author.vue";
import New from "./components/New.vue";

export default {
  name: "App",
  components: {
    Quote,
    Author,
    New,
  },
  data() {
    return {
      selectedComponent: "Quote",
    };
  },
 
};
</script>

<style>
</style>
