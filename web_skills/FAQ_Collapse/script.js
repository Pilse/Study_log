const faqs = document.querySelectorAll('.faq');
const btns = document.querySelectorAll('button');

btns.forEach((btn,idx)=>{
    btn.addEventListener('click',()=>{
        faqs[idx].classList.toggle('active');
    })
})