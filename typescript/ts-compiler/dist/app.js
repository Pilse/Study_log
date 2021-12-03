"use strict";
const button = document.querySelector('button');
function clickHandler(message) {
    console.log('Clicked!' + message);
}
button.addEventListener('click', clickHandler.bind(null, 'You\'re welcome'));
