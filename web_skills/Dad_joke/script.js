const jokeText = document.querySelector('.container .joke');
const btn = document.querySelector('.container .btn');

getJoke();
btn.addEventListener('click',getJoke)
async function getJoke() {
    const res = await fetch('https://icanhazdadjoke.com/',{
        headers:{
            Accept:"application/json"
        }
    });
    const data = await res.json();
    jokeText.innerHTML=data.joke;
}