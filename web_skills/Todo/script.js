const form = document.querySelector('form');
const ul = document.querySelector('ul');
const input = document.querySelector('.input');


form.addEventListener('submit',(e)=>{
    e.preventDefault();

    const todo = input.value;

    if(todo) {
        const todoEl = document.createElement('li');
        todoEl.innerText = todo;

        todoEl.addEventListener('click',()=>{
            todoEl.classList.toggle('completed');
        });
        todoEl.addEventListener('contextmenu',(e)=>{
            e.preventDefault();
            todoEl.remove();
        });

        ul.appendChild(todoEl);

        input.value = '';
    }
})