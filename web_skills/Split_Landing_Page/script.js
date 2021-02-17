const left = document.querySelector('.left');
const right = document.querySelector('.right');

left.addEventListener('mouseover',()=>{
    left.classList.add('hover');
    right.classList.add('other');
})

left.addEventListener('mouseout',()=>{
    left.classList.remove('hover');
    right.classList.remove('other');
})


right.addEventListener('mouseover',()=>{
    right.classList.add('hover');
    left.classList.add('other');
})

right.addEventListener('mouseout',()=>{
    right.classList.remove('hover');
    left.classList.remove('other');
})