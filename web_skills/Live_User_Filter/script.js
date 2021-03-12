const userList = document.querySelector('.user-list');
const search = document.querySelector('.filter input');

makeUserList();

async function makeUserList() {
    const res = await fetch('https://randomuser.me/api?results=50');
    const { results:users } = await res.json();

    users.forEach(user=>{
        const userEl = document.createElement('div');
        userEl.classList.add('user');
        userEl.innerHTML = `
            <img src=${user.picture.large} alt="">
            <div class="user-info">
                <h4>${user.name.first} ${user.name.last}</h4>
                <p>${user.location.city}, ${user.location.country}</p>
            </div>
        `
        userList.appendChild(userEl);
    })
   
}
function filterUser(input){
    const users = document.querySelectorAll('.user-list .user');
    users.forEach(user=>{
        if(user.innerText.toLowerCase().includes(input.toLowerCase())) {
            user.classList.remove('hidden');
        } else {
            user.classList.add('hidden')
        }
    })
}


search.addEventListener('input',(e)=>{
    filterUser(e.target.value);
})