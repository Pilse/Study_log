const quizData = [
    {
        question: "Which language runs in a web browser?",
        a: "Java",
        b: "C",
        c: "Python",
        d: "JavaScript",
        correct: "d",
    }, 
    {
        question: "What does CSS stand for?",
        a: "Central Style Sheets",
        b: "Cascading Style Sheets",
        c: "Cascading Simple Sheets",
        d: "Cars SUVs Sailboats",
        correct: "b",
    },
    {
        question: "What does HTML stand for?",
        a: "Hypertext Markup Language",
        b: "Hypertext Markdown Language",
        c: "Hyperloop Machine Language",
        d: "Helicopters Terminals Motorboats Lamborginis",
        correct: "a",
    },
    {
        question: "What year was JavaScript launched?",
        a: "1996",
        b: "1995",
        c: "1994",
        d: "none of the above",
        correct: "b",
    },
];

const answers = document.querySelectorAll('.answer');
const submit = document.querySelector('.submit');
const aEl = document.querySelector('.a-text');
const bEl = document.querySelector('.b-text');
const cEl = document.querySelector('.c-text');
const dEl = document.querySelector('.d-text');
const quizContent = document.querySelector('.quiz-content h2');
const quizContainer = document.querySelector('.quiz-container');

let cur = 0;
let score = 0;

getQuiz();
function deleteSelected(){
    answers.forEach(ans=>{
        ans.checked=false;
    })
}
function getQuiz(){
    deleteSelected();
    if(cur==4) {
        quizContainer.innerHTML=`<h2 class="result">You score ${score}/4 !</h2>`
    } else {
    const currentQuiz = quizData[cur];
    quizContent.innerText = currentQuiz.question;
    aEl.innerText  = currentQuiz.a;
    bEl.innerText  = currentQuiz.b;
    cEl.innerText  = currentQuiz.c;
    dEl.innerText  = currentQuiz.d;
    }
}

function getAnswer(){
    let answer;
    answers.forEach(ans=>{
        if(ans.checked)
            answer = ans.id;
    })
    return answer;
}

function checkAnswer(ans){
    if(ans === quizData[cur].correct) {
        score++;
    }
}

submit.addEventListener('click',()=>{
    const answer = getAnswer();
    checkAnswer(answer);
    cur++;
    getQuiz();
})
