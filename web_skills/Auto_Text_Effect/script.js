const textEl = document.querySelector('h2');
const speedEl = document.querySelector('input');

let speed = 300 / speedEl.value;
let idx = 0;

autoText();

function autoText () {
    idx++;
    const text = 'I love programming!! Do you love programming?   ';
    if(idx>text.length){
        idx=0;
    }
    textEl.innerText = text.slice(0, idx);

    setTimeout(autoText,speed);
}


speedEl.addEventListener('input',(e)=>{
    if(e.target.value === '') {
        e.target.value = 1;
    }
    if(e.target.value > 5) {
        e.target.value = 5;
    }
    speed = 300 / e.target.value;
})