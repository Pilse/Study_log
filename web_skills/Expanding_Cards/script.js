const pannels = document.querySelectorAll('.pannels');

pannels.forEach(pannel=>{
    pannel.addEventListener('click',()=>{
        removeActive();
        pannel.classList.add('active');
    })
})

function removeActive(){
    pannels.forEach(pannel=>{
        pannel.classList.remove('active');
    })
}