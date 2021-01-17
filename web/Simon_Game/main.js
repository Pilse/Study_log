var level = 1;
var userInput = [];
var simonInput = [];
var isStart = false;
var isGameOver = false;

$('.btn').click(function () {
    makeSound(this.id);
    makeAnimation(this.id)
    if (isStart) {
        switch (this.id) {
            case 'green':
                userInput.push(1);
                if (!isSimonRight()) {
                    gameOver();
                }
                break;
            case 'red':
                userInput.push(2);
                if (!isSimonRight()) {
                    gameOver();
                }
                break;
            case 'yellow':
                userInput.push(3);
                if (!isSimonRight()) {
                    gameOver();
                }
                break;
            case 'blue':
                userInput.push(4);
                if (!isSimonRight()) {
                    gameOver();
                }
                break;
            default:
                break;
        }
    }
    if (isStart && (simonInput.length === userInput.length)) {
        userInput = [];
        showLevel();
        setTimeout(function () {
            makeSimon();
        }, 500);
    }
});


$(document).keydown(function (event) {
    if (!isGameOver && (event.key === 'a' || event.key === 'A')) {
        if (!isStart) {
            isStart = true;
            showLevel();
            setTimeout(function () {
                makeSimon();
            }, 500);
        }
    }
    if (isGameOver) {
        isGameOver=false;
        isStart = true;
        showLevel();
        setTimeout(function () {
            makeSimon();
        }, 500);

    }
});





function makeSound(key) {
    var sound = new Audio('sounds/' + key + '.mp3');
    sound.play();
}

function makeAnimation(key) {
    $('.' + key).addClass('pressed');
    setTimeout(function () {
        $('.' + key).removeClass('pressed');
    }, 100);
}

function showLevel() {
    $('h1').html('LEVEL ' + level++);
}
function makeSimon() {
    var randomNumber = Math.floor(Math.random() * 4 + 1)
    simonInput.push(randomNumber);

    switch (randomNumber) {
        case 1:
            makeSound('green');
            makeAnimation('green');
            break;
        case 2:
            makeSound('red');
            makeAnimation('red');
            break;
        case 3:
            makeSound('yellow');
            makeAnimation('yellow');
            break;
        case 4:
            makeSound('blue');
            makeAnimation('blue');
            break;
    }
}

function isSimonRight() {

    var length = userInput.length;
    for (var i = 0; i < length; i++) {
        if (userInput[i] !== simonInput[i])
            return false;
    }
    return true;
}

function gameOver() {
    isGameOver = true;
    isStart = false;
    userInput = [];
    simonInput = [];
    level = 1;
    $('h1').html('Game Over, Press Any Key to Restart');
    makeSound('wrong');
    $('body').addClass('game-over');
    setTimeout(function () {
        $('body').removeClass('game-over');
    }, 100);
}
