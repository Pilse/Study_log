const input = document.querySelector('.range-container input');
const label = document.querySelector('.range-container label');
const range = document.querySelector('.range-container');

input.addEventListener('input',(e)=>{
    label.innerHTML = e.target.value;
    label.style.left = `calc(15px + ${e.target.value * 0.9}%)`;
})
