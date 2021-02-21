const API_URL = 'https://api.themoviedb.org/3/discover/movie?sort_by=popularity.desc&api_key=af1ce389bb8aeed0a8289a5619c9d045';
const IMG_URL = 'https://image.tmdb.org/t/p/w1280';
const SERCH_URL = 'https://api.themoviedb.org/3/search/movie?api_key=af1ce389bb8aeed0a8289a5619c9d045&query="';
const main = document.querySelector('.main');
const form = document.querySelector('.form');
const search = document.querySelector('.form input');

getMovies(API_URL);
async function getMovies (url) {
    const res = await fetch(url);
    const data = await res.json();
    updateMain(data.results);
}
form.addEventListener('submit',(event)=>{
    event.preventDefault();
    getMovies(SERCH_URL + search.value);
    search.value='';
})

function updateMain(movies) {
    main.innerHTML='';
    movies.map(movie=>{
        let imgSrc=''
        const {overview, poster_path, title, vote_average} = movie;
        if(poster_path===null){
            imgSrc='https://www.setaswall.com/wp-content/uploads/2017/09/320x480-Wallpaper-239.jpg'
        } else {
        imgSrc=IMG_URL + poster_path;
        }
        const color = getColor(vote_average);
        const movieEL = document.createElement('div');
        movieEL.classList.add('movie');
        movieEL.innerHTML=`
        <img src="${imgSrc}" alt="">
        <div class="movie-info">
            <h3>${title}</h3>
            <span class="${color}">${vote_average}</span>
        </div>
        <div class="overview">
            ${overview}
        </div>
        `
        main.appendChild(movieEL);
    })
}

function getColor(num) {
    if(num<4)
    return 'red';
    if(num<7)
    return 'orange';
    if(num<=10)
    return 'green';
}