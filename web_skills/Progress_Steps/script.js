const prev = document.querySelector('#prev');
const next = document.querySelector('#next');
const progress = document.querySelector('#progress');
const active = document.querySelectorAll('.active');
const circles = document.querySelectorAll('.circle');

let currentCount = 1;

next.addEventListener('click',()=>{
    currentCount++;
    if(currentCount>circles.length){
        currentCount=circles.length;
    }
    update();
})

prev.addEventListener('click',()=>{
    currentCount--;
    if(currentCount<1){
        currentCount=1;
    }
    update();
})

function update() {
    progress.style.width=((currentCount-1)/(circles.length-1))*100+'%';
    circles.forEach((circle,index)=>{
        if(index<=currentCount-1){
            circle.classList.add('active');
        }else{
            circle.classList.remove('active')
        }
    })
    if (currentCount===circles.length){
        next.disabled=true;
    } else if(currentCount===1){
        prev.disabled=true;
    } else {
        next.disabled=false;
        prev.disabled=false;
    }
}