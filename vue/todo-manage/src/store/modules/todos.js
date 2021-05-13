const state = {
    todos: []
};

const getters = {
    allTodos: (state) => state.todos
};

const actions = {
    async fetchTodos({ commit }) {
        const res = await fetch('https://jsonplaceholder.typicode.com/todos');
        const data = await res.json();

        commit('setTodos', data);
    },
    async addTodo({ commit }, title) {
        const res = await fetch('https://jsonplaceholder.typicode.com/todos',{
            method: 'POST',
            headers:{
                'Content-Type':'application/json'
            },
            body: JSON.stringify(
                {
                    title,
                    completed:false
                }),
        });
        const data = await res.json();

        commit('newTodo', data);
    }
};

const mutations = {
    setTodos: (state, todos) => (state.todos = todos),
    newTodo: (state, todo) => state.todos.unshift(todo)
};

export default {
    state,
    getters,
    actions,
    mutations
}