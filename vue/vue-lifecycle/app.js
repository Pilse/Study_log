const app = Vue.createApp({
  data() {
    return {
      currentUserInput: '',
      message: 'Vue is great!',
    };
  },
  methods: {
    saveInput(event) {
      this.currentUserInput = event.target.value;
    },
    setText() {
      // this.message = this.currentUserInput;
      this.message = this.$refs.userText.value
    },
  },
  befroeCreate(){
    // You could make a http request
    console.log('beforeCreate()');
  },
  created() {
    console.log('created()');
  },
  beforeMount(){
    console.log('beforeMount()');
  },
  mounted(){
    console.log('mounted()');
  },
  beforeUpdate() {
    console.log('beforeUpdate()');
  },
  updated() {
    console.log('updated()');
  }
});

app.mount('#app');

// How Vue updates data

// const data ={
//   message: 'Hello!',
//   longMessage: 'Hello! World!'
// };
// const handler = {
//   set(target, key, value){
//     if(key === 'message') {
//       target.longMessage = value + 'World!';
//     }
//   }
// };
// const proxy = new Proxy(data, handler);