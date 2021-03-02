const APIURL = 'https://api.github.com/users/';
const search = document.querySelector('.search');
const searchUser = search.querySelector('input');
const main = document.querySelector('.main');

function makeErrCard(msg) {
    const cardEl = `
    <div class="card">
        <h1>${msg}</h1>
    </div>
    `
    main.innerHTML = cardEl;
}

function makeCard(user) {
    const cardEl = `
    <div class="card">
        <div class="user-photo">
            <img class="avatar" src="
            ${user.avatar_url}" alt="${user.name}" class="user-profile">
        </div>
        <div class="user-info">
            <h2>${user.name}</h2>
            <p>${user.bio}</p>
            <ul>
                <li>${user.followers} <strong>Followers</strong></li>
                <li>${user.following} <strong>Following</strong></li>
                <li>${user.public_repos} <strong>Repos</strong></li>
            </ul>
            <div class="repos"></div> 
        </div>
    </div>
    `
    main.innerHTML = cardEl;
}

function makeRepo(repos) {

    const reposEl = document.querySelector('.repos');
    console.log(reposEl);
    

    repos.slice(0, 10).forEach(repo=>{
        const repoEl = document.createElement('a');
        repoEl.classList.add('repo');
        repoEl.href = repo.html_url;
        repoEl.target = '_blank';
        repoEl.innerText = repo.name;

        reposEl.appendChild(repoEl);

    })
}

async function getRepo (user) {
    try {
        const response = await fetch(APIURL + user + '/repos?sort=created');
        const data = await response.json();
        
        makeRepo(data);

    } catch(err) {
        makeErrCard('Cannot fetch repos');
    }
}


async function getUser(userName) {
    try {
        const response = await fetch(APIURL + userName);
        const data = await response.json();

        makeCard(data);
        getRepo(userName);

    } catch (err) {
        makeErrCard('Cannot find user in Github');
    }
}

search.addEventListener('submit', (event) => {
    event.preventDefault();

    if(searchUser.value) {
        getUser(searchUser.value);
        searchUser.value = '';
    }
});