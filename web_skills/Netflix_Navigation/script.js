const openBtn = document.querySelector('.open');
const closeBtn = document.querySelector('.close');
const navs = document.querySelectorAll('.nav');
const red = document.querySelector('.red');

openBtn.addEventListener('click',()=>{
    navs.forEach(nav=>{
        nav.classList.add('visible');
    })
    red.setAttribute('tabindex','0');
    red.focus();
})
closeBtn.addEventListener('click',()=>{
    navs.forEach(nav=>{
        nav.classList.remove('visible');
    })
})
red.addEventListener('blur',()=>{
    setTimeout(()=>{
        navs.forEach(nav=>{
            nav.classList.remove('visible');
        })
    },150)
})