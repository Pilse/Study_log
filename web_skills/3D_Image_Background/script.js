const boxes = document.querySelector('.boxes');
const BOXNUM = 16;
const magic = document.querySelector('.btn');

for(let i = 0 ; i < BOXNUM; i++){
    const box = document.createElement('div');
    box.classList.add('box');
    box.style.backgroundPosition = `-${i%4*125}px -${Math.floor(i/4)*125}px`;
    boxes.appendChild(box);
}

magic.addEventListener('click',()=>{
    boxes.classList.toggle('separate');
})