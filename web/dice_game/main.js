function dice() {
    var player1RandomNumber = Math.floor(Math.random() * 6) + 1;
    var player2RandomNumber = Math.floor(Math.random() * 6) + 1;
    var player1Name = document.querySelector('#player1').value;
    var player2Name = document.querySelector('#player2').value;

    document.querySelector('.player1').innerHTML = '<p>player1</p> ';
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
    document.querySelector('.player2').innerHTML = '<p>player2</p> ';
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
        document.querySelector('.winner').innerHTML = 'Player 1 Win!';
    else if (player1RandomNumber < player2RandomNumber)
        document.querySelector('.winner').innerHTML = 'Player 2 Win!';
    else
        document.querySelector('.winner').innerHTML = 'Draw!';
}