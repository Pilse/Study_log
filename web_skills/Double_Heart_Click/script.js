const likeMe = document.querySelector('.like-me');
const time = document.querySelector('.time');

let clickedTime = 0;

likeMe.addEventListener('dblclick',(e)=>{

    const x = window.scrollX + e.clientX - e.target.offsetLeft;
    const y = window.scrollY + e.clientY - e.target.offsetTop;
    
    makeHeart(x, y);
})

function makeHeart(x, y) {
    const heartEl = document.createElement('i');
    heartEl.classList.add('fas');
    heartEl.classList.add('fa-heart');
    heartEl.style.left=`${x}px`;
    heartEl.style.top=`${y}px`;
    likeMe.appendChild(heartEl);

    setTimeout(()=>heartEl.remove(),1000);
    clickedTime++;
    time.innerHTML = clickedTime;
}