const col1 = document.querySelector('.col1');
const col2 = document.querySelector('.col2');
const col3 = document.querySelector('.col3');
const container = document.querySelector('.container');

const rows = 5;
const url = 'https://source.unsplash.com/random/';
let flag = true

function getSize() {
    return (`${(Math.floor(Math.random() * 100) + 300)} x ${(Math.floor(Math.random() * 100) + 300)}`);
}
function makeImg() {
    for (let i = 0; i < rows * 3; i++) {
        const divEl = document.createElement('div');
        divEl.classList.add('image');
        divEl.classList.add('info');
        const imgEl = document.createElement('img');

        divEl.appendChild(imgEl);
        imgEl.src = url + getSize();

        if (i < rows) {
            col1.appendChild(divEl);
        }
        else if (i < rows * 2) {
            col2.appendChild(divEl);
        } else {
            col3.appendChild(divEl);
        }
    }
}

async function getImg() {
    if (flag) {
        flag = false;
        console.log('image');
        await makeImg();
        setTimeout(()=>flag = true,600);
    }
}


getImg();

window.addEventListener('scroll', () => {

    if (container.getBoundingClientRect().bottom - window.innerHeight < 300) {
        getImg();
    }

})