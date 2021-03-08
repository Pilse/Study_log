//api url https://pokeapi.co/api/v2/pokemon/${id}
const container = document.querySelector('.container');
const NUMBER = 150;
const colors = {
    fire: '#FDDFDF',
    grass: '#DEFDE0',
    electric: '#FCF7DE',
    water: '#DEF3FD',
    ground: '#f4e7da',
    rock: '#d5d5d4',
    fairy: '#fceaff',
    poison: '#98d7a5',
    bug: '#f8d5a3',
    dragon: '#97b3e6',
    psychic: '#eaeda1',
    flying: '#F5F5F5',
    fighting: '#E6E0D4',
    normal: '#F5F5F5'
}
getPokemons();

async function getPokemon(_id) {
    const res = await fetch(`https://pokeapi.co/api/v2/pokemon/${_id}`);
    const data = await res.json();
    const { id, name, types, sprites } = data;
    const type = types[0].type.name;
    const img = sprites.front_default;
    const idString = id.toString().padStart(3,'0');

    const pokemon = document.createElement('div');
    pokemon.classList.add('pokemon');
    pokemon.innerHTML = `
        <div class="img-container">
            <img src="https://pokeres.bastionbot.org/images/pokemon/${id}.png" alt="">
        </div>
        <div class="pokemon-info">
            <span class="number">#${idString}</span>
            <h3 class="name">${name}</h3>
            <small class="type" >Type: <span>${type}</span></small>
        </div>
    `;
    pokemon.style.backgroundColor = colors[type];


    container.appendChild(pokemon);


}

function getPokemons() {
    for (let i = 1; i <= NUMBER; i++) {
        getPokemon(i);
    }
}