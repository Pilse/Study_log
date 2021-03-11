const password = document.querySelectorAll('form input')[1];
const container = document.querySelector('.container');

password.addEventListener('input',()=>{
    const length = password.value.length;

    let blur = 10 - length;
    if (blur < 0 ) {
        blur = 0;
    }

    container.style.filter = `blur(${blur}px)`;
})