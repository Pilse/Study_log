const left = document.querySelector('.left-arrow');
const right = document.querySelector('.right-arrow');
const slides = document.querySelectorAll('.slide');
const body = document.body;

let idx=0;

function setBackground(idx) {
    body.style.backgroundImage = slides[idx].style.backgroundImage;
}

right.addEventListener('click',()=>{
    idx++;
    if(idx===slides.length){
        idx=0;
    }
    slides.forEach(slide=>slide.classList.remove('active'));
    slides[idx].classList.add('active');
    setBackground(idx);
});

left.addEventListener('click',()=>{
    idx--;
    if(idx===-1){
        idx=slides.length-1;
    }
    slides.forEach(slide=>slide.classList.remove('active'));
    slides[idx].classList.add('active');
    setBackground(idx);
})