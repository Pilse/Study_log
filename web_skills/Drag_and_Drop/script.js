const empites = document.querySelectorAll('.empty');
const fill = document.querySelector('.fill');

empites.forEach(empty=>{
    empty.addEventListener('dragover',(event)=>{
        event.preventDefault();
    })
    empty.addEventListener('dragenter',(event)=>{
        event.preventDefault();
        empty.classList.add('hovered');
    })
    empty.addEventListener('dragleave',()=>{
        empty.classList.remove('hovered');
    })
    empty.addEventListener('drop',()=>{
        empty.classList.remove('hovered');
        empty.appendChild(fill);
    })
})
fill.addEventListener('dragstart',()=>{
    setTimeout(()=>fill.className='invisible',0);
})
fill.addEventListener('dragend',()=>{
    fill.className='fill'
})