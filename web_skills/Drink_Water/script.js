const smallCups = document.querySelectorAll('.cups .cup');
const liter = document.querySelector('.liter');
const percentage = document.querySelector('.percentage');
const remained = document.querySelector('small');

smallCups.forEach((smallCup,idx)=>{
    smallCup.addEventListener('click',()=>{
        fillCups(idx);
        updateRemain();
    })
})

function fillCups(idx) {
    if(smallCups[idx].classList.contains('full') && !smallCups[idx+1].classList.contains('full')){
        idx--;
    }
    smallCups.forEach((smallCup,idx2)=>{
        if(idx2<=idx){
            smallCup.classList.add('full');
        } else {
            smallCup.classList.remove('full');
        }
    })
}

function updateRemain(){
    const fullCups = document.querySelectorAll('.full');
    if(fullCups.length===0) {
        percentage.style.height=0;
        liter.innerText=`${2 - 0.25*fullCups.length} L`
    } else {
        percentage.style.height= `${fullCups.length / smallCups.length * 100}%`;
        percentage.innerText = `${fullCups.length / smallCups.length * 100}%`;
        liter.innerText=`${2 - 0.25*fullCups.length} L`
    }
   if(fullCups.length===smallCups.length){
       liter.style.display='none';
       remained.style.display='none';
   } else {
        liter.style.display='flex';
        remained.style.display='flex';
   }
        
}