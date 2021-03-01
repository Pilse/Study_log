const btn = document.querySelectorAll('.btn');
const notif = document.querySelector('.notif');
const body = document.body;

btn[0].addEventListener('click',()=>{
    const toastEl = document.createElement('div');
    toastEl.classList.add('toast');
    toastEl.innerText=`hello there ${Math.floor(Math.random()*10)}`;
    notif.appendChild(toastEl);
    setTimeout(()=>{
        toastEl.remove();
    },3000);
})
btn[1].addEventListener('click',()=>{
    const msgEl = document.createElement('div');
    msgEl.classList.add('message');
    msgEl.innerHTML=` <p>Lorem ipsum dolor sit amet consectetur adipisicing elit. Facilis veritatis aliquid, delectus odio ad hic, tempore consequatur provident omnis iste itaque doloribus excepturi. Ea quibusdam magnam ab accusantium consectetur consequatur.</p>`
    body.appendChild(msgEl);

    const p = msgEl.querySelector('p');
    p.setAttribute('tabindex','0');
    p.setAttribute('spellcheck','false');
    p.focus();
    p.addEventListener('blur',()=>{
        console.log(123);
        msgEl.remove();
    })
})