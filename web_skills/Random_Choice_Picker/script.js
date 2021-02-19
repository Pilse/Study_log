const textarea = document.querySelector('#textarea');
const tags = document.querySelector('.tags');


textarea.focus();

textarea.addEventListener('keyup',(e)=>{
    const inputs = makeTags(e.target.value);

    tags.innerHTML=''

    inputs.forEach(input=>{
        const tagEl=document.createElement('span');
        tagEl.classList.add('tag');
        tagEl.innerText=input;
        tags.appendChild(tagEl);
    })
    if(e.key==='Enter')
    {
        randomPick(inputs);
        e.target.value='';
    }

})

function makeTags(keys){
    return keys.split(',').filter(key=>key.trim()!=='').map(key=>key.trim());
}

function randomPick(keys){
    const times=30;
    const tag = document.querySelectorAll('.tag');
    const interval = setInterval(()=>{

        const random = Math.floor(Math.random()*keys.length);
        tag[random].classList.add('choice');

        setTimeout(()=>{
            tag[random].classList.remove('choice')
        },100);
    },200)
    setTimeout(() => {
        clearInterval(interval);
        const random = Math.floor(Math.random()*keys.length);
        tag[random].classList.add('choice');
    }, times*200);
}
