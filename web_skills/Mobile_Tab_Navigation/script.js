const navs = document.querySelectorAll('ul li');
const imgs = document.querySelectorAll('.phone .content');


function changeDisplay(id) {
    imgs.forEach((img,idx)=>{
        if(id===idx) {
            img.classList.add('show');
        } else {
            img.classList.remove('show');
        }
    })
}
function toggleActive(id) {
    navs.forEach((nav,idx)=>{
        if(id===idx) {
            nav.classList.add('active');
        } else {
            nav.classList.remove('active');
        }
    })
} 

navs.forEach((nav,idx) => {
    nav.addEventListener('click',()=>{
        toggleActive(idx);
        changeDisplay(idx);
    })
})