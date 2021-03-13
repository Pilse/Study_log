const ratings = document.querySelectorAll('.rating');
const pannel = document.querySelector('.pannel-container');
const send = document.querySelector('button');

let feedback = 'Satisfied'

function removeActive() {
    ratings.forEach(rating=>rating.classList.remove('active'));
}

ratings.forEach(rating=>{
    rating.addEventListener('click',()=>{
        removeActive();
        rating.classList.add('active');
        feedback = rating.querySelector('small').innerText;
    })
})

send.addEventListener('click',()=>{
    pannel.innerHTML=`
        <i class="fas fa-heart"></i>
        <p>Thank You!</p>
        <br>
        <strong style="color:green;">'${feedback}'</strong>
        <br>
        <p style="text-align:left;">It will be used to improve our customer support</p>
    `
})