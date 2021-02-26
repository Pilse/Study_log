const cardHeader = document.querySelector('.card-header');
const title = document.querySelector('.title');
const context = document.querySelector('.context');
const profileImg = document.querySelector('.profile-img');
const author = document.querySelector('.author');
const date = document.querySelector('.date');
const bgAnimateds = document.querySelectorAll('.bg-animated');

setTimeout(getData,2000);

function getData() {
    cardHeader.innerHTML = `<img src="https://images.unsplash.com/photo-1531934788018-04c3cd417b80?ixid=MXwxMjA3fDB8MHxzZWFyY2h8NXx8bWFjfGVufDB8fDB8&ixlib=rb-1.2.1&auto=format&fit=crop&w=500&q=60"
    alt="">`;
    title.innerHTML=`Lorem ipsum dolor sit amet`;
    context.innerHTML=`Lorem ipsum dolor sit amet consectetur adipisicing elit Vero fugit`;
    profileImg.innerHTML=`<img src="https://randomuser.me/api/portraits/men/45.jpg" alt="" />`;
    author.innerHTML=`John Doe`;
    date.innerHTML=`26, February`;

    bgAnimateds.forEach(bg=>{
        bg.classList.remove('bg-animated');
        bg.classList.remove('bg-animated-text');
    })
}