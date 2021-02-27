const upBtn = document.querySelector('.up-button');
const downBtn = document.querySelector('.down-button');
const leftSlide = document.querySelector('.left-slide');
const rightSlide = document.querySelector('.right-slide');
const Slidelength = rightSlide.querySelectorAll('div').length;

let curSlideLength = 1;
console.log(Slidelength)

leftSlide.style.top= `-${(Slidelength-1) * 100}%`

upBtn.addEventListener('click',()=>changeSlide('up'));
downBtn.addEventListener('click',()=>changeSlide('down'));


function changeSlide(direction) {
    if(direction==='up') {
        curSlideLength++;
        if(curSlideLength>Slidelength) {
            curSlideLength=1;
        }
    }

    if(direction==='down') {
        curSlideLength--;
        if(curSlideLength<1) {
            curSlideLength=Slidelength;
        }
    }
    
    leftSlide.style.transform=`translateY(${(curSlideLength-1) * 100}%)`
    rightSlide.style.transform=`translateY(-${(curSlideLength-1) * 100}%)`

}