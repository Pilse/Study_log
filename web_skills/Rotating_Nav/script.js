const opens  = document.querySelector('#open');
const closes = document.querySelector('#close');
const container = document.querySelector('.container');
const circle = document.querySelector('.circle');

opens.addEventListener('click',()=>{
    container.classList.add('rotate');
    circle.classList.add('rotate');
})

closes.addEventListener('click',()=>{
    container.classList.remove('rotate');
    circle.classList.remove('rotate');
})