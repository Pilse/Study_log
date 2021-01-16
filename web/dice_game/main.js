
document.querySelector('.player1').innerHTML = '<div class="name"><p>player1</p></div> <input type="text" id="player1">'
document.querySelector('.player2').innerHTML = '<div class="name"><p>player2</p></div> <input type="text" id="player2">'
document.querySelector('.dicebtn').innerHTML = '<input type="submit" name="dice!" value="dice!" class="startgame" onclick="dice();">'
document.querySelector('.winner').innerHTML='Dice game'
var player1Name;
var player2Name;
var iteration = 0;

function dice() {
    var player1RandomNumber = Math.floor(Math.random() * 6) + 1;
    var player2RandomNumber = Math.floor(Math.random() * 6) + 1;


    if(iteration===0)
    {
        player1Name = document.querySelector('#player1').value;
        player2Name = document.querySelector('#player2').value;
        

        iteration=1;
    }
    
    document.querySelector('.dicebtn').innerHTML = '<input type="submit" name="dice!" value="retry" class="startgame" onclick="dice();">'
    document.querySelector('.player1').innerHTML =  '<p>'+player1Name+'</p>';
    switch (player1RandomNumber) {
        case 1:
            document.querySelector('.player1').innerHTML += '<i class="fas fa-dice-one fa-10x dice"></i>';
            break;
        case 2:
            document.querySelector('.player1').innerHTML += '<i class="fas fa-dice-two fa-10x dice"></i>';
            break;
        case 3:
            document.querySelector('.player1').innerHTML += '<i class="fas fa-dice-three fa-10x dice"></i>';
            break;
        case 4:
            document.querySelector('.player1').innerHTML += '<i class="fas fa-dice-four fa-10x dice"></i>';
            break;
        case 5:
            document.querySelector('.player1').innerHTML += '<i class="fas fa-dice-five fa-10x dice"></i>';
            break;
        case 6:
            document.querySelector('.player1').innerHTML += '<i class="fas fa-dice-six fa-10x dice"></i>';
            break;
        default:
            alert('dice error');
            break;
    }
    document.querySelector('.player2').innerHTML = '<p>'+player2Name+'</p>';
    switch (player2RandomNumber) {
        case 1:
            document.querySelector('.player2').innerHTML += '<i class="fas fa-dice-one fa-10x dice"></i>';
            break;
        case 2:
            document.querySelector('.player2').innerHTML += '<i class="fas fa-dice-two fa-10x dice"></i>';
            break;
        case 3:
            document.querySelector('.player2').innerHTML += '<i class="fas fa-dice-three fa-10x dice"></i>';
            break;
        case 4:
            document.querySelector('.player2').innerHTML += '<i class="fas fa-dice-four fa-10x dice"></i>';
            break;
        case 5:
            document.querySelector('.player2').innerHTML += '<i class="fas fa-dice-five fa-10x dice"></i>';
            break;
        case 6:
            document.querySelector('.player2').innerHTML += '<i class="fas fa-dice-six fa-10x dice"></i>';
            break;
        default:
            alert('dice error');
            break;
    }

    if (player1RandomNumber > player2RandomNumber)
        document.querySelector('.winner').innerHTML = player1Name+' Win!';
    else if (player1RandomNumber < player2RandomNumber)
        document.querySelector('.winner').innerHTML = player2Name+' Win!';
    else
        document.querySelector('.winner').innerHTML = 'Draw!';
}