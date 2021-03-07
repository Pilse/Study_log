const next = document.querySelector('.btn.next');
const prev = document.querySelector('.prev');
const imgContainer = document.querySelector('.img-container');
const length = imgContainer.querySelectorAll('img').length;
const btns = document.querySelectorAll('.btn');

let idx = 0;
let cur = 0;

next.addEventListener('click',()=> {
    idx++;
    if(idx>length-1){
        idx=length-1;
    }
    else{
        cur += -400;
        imgContainer.style.transform = `translateX(${cur}px)`;
    }
});
prev.addEventListener('click',()=> {
    idx--;
    if(idx < 0){
        idx = 0;
    }
    else{
        cur += 400;
        imgContainer.style.transform = `translateX(${cur}px)`;
    }
});

btns.forEach(btn=>{
    btn.addEventListener('click',(e)=>{
        const x = e.clientX - e.target.offsetLeft;
        const y = e.clientY - e.target.offsetTop;
        const effectEl = document.createElement('div');
        effectEl.classList.add('effect');
        effectEl.style.top = `${y}px`;
        effectEl.style.left = `${x}px`;
        btn.appendChild(effectEl);

        setTimeout(()=>effectEl.remove(),300);
    })
})
