const screens = document.querySelectorAll('.screen');
const startBtn = document.querySelector('.btn.start');
const insectBtns = document.querySelectorAll('.btn.insect');
const spiderBtn = document.querySelector('.btn.spider');
const mosquitoBtn = document.querySelector('.btn.mosquito');
const gameContainer = document.querySelector('.game-container');
const timer = document.querySelector('.time');
const scoreEl = document.querySelector('.score');
const msgEl = document.querySelector('.msg');

let insect;
let totalInsect = 0;
let score = 0;
let time = 0;

const insectImg = {
    fly: 'http://pngimg.com/uploads/fly/fly_PNG3946.png',
    mosquito: 'http://pngimg.com/uploads/mosquito/mosquito_PNG18175.png',
    spider: 'http://pngimg.com/uploads/spider/spider_PNG12.png'
}

startBtn.addEventListener('click', () => {
    screens[0].classList.add('on');
})

insectBtns.forEach(insectBtn => {
    insectBtn.addEventListener('click', () => {
        insect = insectBtn.innerText;
        screens[1].classList.add('on');
        startTimer();
        gameStart();
    })
});
function startTimer() {
    setInterval(() => {
        time++;
        const minute = Math.floor(time / 60);
        const second = time % 60;
        timer.innerText = `Time: ${minute.toString().padStart(2, '0')}:${second.toString().padStart(2, '0')}`
    }, 1000);
}
function msgAppear(){
    msgEl.classList.add('show');
}
function updateScore() {
    scoreEl.innerText = 'Score: ' + score;
    if(score >= 20){
        msgAppear();
    }
}

function gameStart() {
    console.log(totalInsect);
    if (totalInsect < 1000) {
        totalInsect++;
        const selectedInsect = insectImg[insect];

        const insectEl = document.createElement('div');
        insectEl.classList.add('game-insect');
        const imgEl = document.createElement('img');
        imgEl.src = selectedInsect;
        insectEl.appendChild(imgEl);

        insectEl.style.top = getRandomTop()+100 + 'px';
        insectEl.style.left = getRandomLeft()-100 + 'px';
        imgEl.style.transform = getRandomRoate();

        insectEl.addEventListener('click', () => {
            score++;
            updateScore();
            totalInsect--;
            insectEl.classList.add('caught');
            setTimeout(()=>{
                insectEl.remove();
                gameStart();
            },1000)
            gameStart();
        });

        gameContainer.appendChild(insectEl);

        setTimeout(() => {
            gameStart();
        }, Math.floor(Math.random() * 5000));
    }
}

function getRandomTop() {
    return window.innerHeight - (Math.random() * window.innerHeight);
}
function getRandomLeft() {
    return window.innerWidth - (Math.random() * window.innerWidth);
}
function getRandomRoate() {
    const randomNum = Math.floor(Math.random() * 360);
    return `rotate(${randomNum}deg)`;
}


