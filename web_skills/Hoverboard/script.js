const container = document.querySelector('.square-container');

const SQUARE = 552;

for(let i = 0 ;i < SQUARE ;i ++) {
    const squreEl = document.createElement('div');
    squreEl.classList.add('square');

    squreEl.addEventListener('mouseover',()=> {
        makeColor(squreEl);
    });

    squreEl.addEventListener('mouseout',()=> {
        removeColor(squreEl);
    });
    container.appendChild(squreEl);
}

function getRandomColor() {
    return '#' + Math.random().toString(16).substr(-6);
}
function makeColor(square) {
    const color = getRandomColor();
    square.style.backgroundColor = color;
    square.style.boxShadow = `0 0 10px ${color}`;
}
function removeColor(square) {
    const color = '#222';
    square.style.backgroundColor = color;
    square.style.boxShadow = `0 0 10px ${color}`;
}
