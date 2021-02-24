const buttons = document.querySelectorAll('.ripple');

buttons.forEach(button => {
    button.addEventListener('click',(event)=>{
        const x = event.clientX - event.target.offsetLeft;
        const y = event.clientY - event.target.offsetTop;
        
        button.innerHTML=`Click me <span class="circle" style="top:${y}px; left:${x}px;"></span>`
    })
})