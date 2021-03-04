const lengthEl = document.querySelector('#length');
const uppercaseEl = document.querySelector('#uppercase');
const lowercaseEl = document.querySelector('#lowercase');
const numberEl = document.querySelector('#number');
const symbolEl = document.querySelector('#symbol');
const generateEl = document.querySelector('.submit');
const resultEl = document.querySelector('.result');
const copyEl = document.querySelector('.copy');

const getFunctions = {
    uppercase: getRandomUpper,
    lowercase: getRandomLower,
    number: getRandomNumber,
    symbol: getRandomSymbol
};

function shuffle(password) {
    for (let i = password.length - 1; i > 0; i--) {
        let j = Math.floor(Math.random() * (i + 1));

        let t = password[i]; 
        password[i] = password[j];
        password[j] = t
    }
    return password;
}
function generate(typeArr, length) {
    let password = ''

    if (typeArr.length === 0) {
        return password;
    }

    for (let i = 0; i < length; i += typeArr.length) {
        typeArr.forEach(type => {
            password += getFunctions[Object.keys(type)[0]]();
        });
    }
    
    const finalPassword = shuffle(password);
    return finalPassword;

}

generateEl.addEventListener('click', () => {
    const length = +lengthEl.value;
    const uppercase = uppercaseEl.checked;
    const lowercase = lowercaseEl.checked;
    const number = numberEl.checked;
    const symbol = symbolEl.checked;

    const typeArr = [{ uppercase }, { lowercase }, { number }, { symbol }].filter(item => Object.values(item)[0]);

    resultEl.innerText = generate(typeArr, length);
});
copyEl.addEventListener('click',()=>{
    const textEl = document.createElement('textarea');
    const password = resultEl.innerText;
    if(!password) {
        return;
    }

    textEl.value = password;
    document.body.appendChild(textEl);
    textEl.select();
    document.execCommand('copy');
    textEl.remove();

    const resultContainer = document.querySelector('.result-container');

    const copied = document.createElement('div');
    copied.classList.add('bubble');
    copied.innerText='coppied!'
    resultContainer.appendChild(copied);
    setTimeout(()=>copied.remove(),3000);
})






function getRandomLower() {
    return String.fromCharCode(Math.floor(Math.random() * 26) + 97);
}
function getRandomUpper() {
    return String.fromCharCode(Math.floor(Math.random() * 26) + 65);
}
function getRandomNumber() {
    return String.fromCharCode(Math.floor(Math.random() * 10) + 48);
}
function getRandomSymbol() {
    const symbols = '~!@#$%^&*()_+=/?;:<>[]{}';
    return symbols[Math.floor(Math.random() * symbols.length)];
}

