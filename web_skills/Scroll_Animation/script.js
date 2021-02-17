const contents = document.querySelectorAll('.content');

window.addEventListener('scroll',()=>{
    const trigger = window.innerHeight*4/5;
    contents.forEach(content=>{
        const boxTop = content.getBoundingClientRect().top;
        if(boxTop<trigger){
            content.classList.add('show');
        } else {
            content.classList.remove('show');
        }
    })
})