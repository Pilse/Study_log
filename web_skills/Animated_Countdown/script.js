const nums = document.querySelectorAll('.nums .num');
const counter = document.querySelector('.counter');
const final = document.querySelector('.final');
const replay = document.querySelector('.replay');

const length = nums.length - 1;

makeAnimation();

function makeAnimation() {
    nums.forEach((num, idx) => {
        num.addEventListener('animationend',(e)=>{
            if(idx !== length && e.animationName === 'goIn') {
                num.classList.remove('in');
                num.classList.add('out');
            } else if(idx !== length && e.animationName ==='goOut') {
                num.nextElementSibling.classList.add('in');
            } else {
                counter.classList.add('hide');
                final.classList.remove('hide');
            }
        })
    })
}

function replayAnimation() {
    nums.forEach((num, idx) => {
        num.classList.remove('out');
        num.classList.remove('in');
    });
    counter.classList.remove('hide');
    final.classList.add('hide');
    nums[0].classList.add('in');
}

replay.addEventListener('click',()=>{
    replayAnimation();
    makeAnimation();
})

