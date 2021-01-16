var length =document.querySelectorAll('button').length;

for(var i=0;i<length;i++){
document.querySelectorAll('.drum')[i].addEventListener('click',function (){
    makeSound(this.innerHTML);
    buttonAnimation(this.innerHTML);
});
}


addEventListener('keydown',function(event){
    makeSound(event.key);
    buttonAnimation(event.key);

});

document.querySelector('.clear').addEventListener('click',function(){
    document.querySelector('.sheet').innerHTML =' '
})

function makeSound(key){
    switch (key) {
        case 'w':
            var tom1 = new Audio('sounds/tom-1.mp3');
            tom1.play();
            maintain(document.querySelector('.sheet').innerHTML.length);
            document.querySelector('.sheet').innerHTML+=key;
            break;
        case 'a':
            var tom2 = new Audio('sounds/tom-2.mp3');
            tom2.play();
            maintain(document.querySelector('.sheet').innerHTML.length);
            document.querySelector('.sheet').innerHTML+=key;
            break;
        case 's':
            var tom3 = new Audio('sounds/tom-3.mp3');
            tom3.play();
            maintain(document.querySelector('.sheet').innerHTML.length);
            document.querySelector('.sheet').innerHTML+=key;
            break;
        case 'd':
            var tom4 = new Audio('sounds/tom-4.mp3');
            tom4.play();
            maintain(document.querySelector('.sheet').innerHTML.length);
            document.querySelector('.sheet').innerHTML+=key;
            break;
        case 'j':
            var snare = new Audio('sounds/snare.mp3');
            snare.play();
            maintain(document.querySelector('.sheet').innerHTML.length);
            document.querySelector('.sheet').innerHTML+=key;
            break;
        case 'k':
            var crash = new Audio('sounds/crash.mp3');
            crash.play();
            maintain(document.querySelector('.sheet').innerHTML.length);
            document.querySelector('.sheet').innerHTML+=key;
            break;
        case 'l':
            var kick = new Audio('sounds/kick-bass.mp3');
            kick.play();
            maintain(document.querySelector('.sheet').innerHTML.length);
            document.querySelector('.sheet').innerHTML+=key;
            break;
        default:
            break;
    }

}

function buttonAnimation(currentkey){
    var activeButton = document.querySelector('.' + currentkey);
    activeButton.classList.add('pressed');
    setTimeout(function() {
        activeButton.classList.remove('pressed');
    },100);
}

function maintain(length){
    if(length%19===18)
    {
        document.querySelector('.sheet').innerHTML +=' <br>'
    }
}

