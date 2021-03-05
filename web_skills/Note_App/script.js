const addBtn = document.querySelector('.add');
const body = document.body;
const notes = JSON.parse(localStorage.getItem('notes'));

if(notes) {
    notes.forEach(note=>addNotes(note));
}

function updateLS() {
    const texts = document.querySelectorAll('textarea');
    const notes = [];

    texts.forEach(text=>{
        notes.push(text.value);
    })
    localStorage.setItem('notes',JSON.stringify(notes));
}

function addNotes(text = '') {
    const noteEl = document.createElement('div');
    noteEl.classList.add('note');
    noteEl.innerHTML = `
        <div class="tools">
        <button class="edit">
            <i class="fas fa-edit"></i>
        </button>
        <button class="delete">
            <i class="fas fa-trash-alt"></i>
        </button>
        </div>
        <div class="main ${text ? '' : 'hidden'}"></div>
        <textarea class="${text ? 'hidden' : ''}" cols="30" rows="10"></textarea>
    `
    const main = noteEl.querySelector('.main');
    const editBtn = noteEl.querySelector('.edit');
    const deleteBtn = noteEl.querySelector('.delete');
    const textarea = noteEl.querySelector('textarea');
    const tools = noteEl.querySelector('.tools');

    main.innerHTML = marked(text);
    textarea.value= text;

    if(!textarea.classList.contains('hidden')) {
        textarea.focus();
        tools.style.backgroundColor = 'green';
    } else {
        tools.style.backgroundColor = 'rgb(88, 152, 88)';
    }

    body.appendChild(noteEl);

    editBtn.addEventListener('click', () => {
        main.classList.toggle('hidden');
        textarea.classList.toggle('hidden');

        if(!textarea.classList.contains('hidden')) {
            textarea.focus();
            tools.style.backgroundColor = 'green';
        } else {
            tools.style.backgroundColor = 'rgb(88, 152, 88)';
        }

        main.innerHTML = marked(textarea.value);
        updateLS();
    });

    deleteBtn.addEventListener('click', () => {
        noteEl.remove();
        updateLS();
    })
}

addBtn.addEventListener('click', () => {
    addNotes();
})