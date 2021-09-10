const movieData = [
  {
    name: 'Avengers: Endgame',
    contentRating: '12A',
    duration: 181, // in minutes
    starRating: 8.4, // out of 10
    votes: 747374,
    gross: 858 // USD million
  },
  {
    name: 'The Lion King',
    contentRating: 'PG',
    duration: 118,
    starRating: 6.9,
    votes: 198014,
    gross: 544
  },
  {
    name: 'Star Wars: The Rise of Skywalker',
    contentRating: '12A',
    duration: 141,
    starRating: 6.6,
    votes: 343828,
    gross: 515
  },
  {
    name: 'Frozen 2',
    contentRating: 'U',
    duration: 103,
    starRating: 6.9,
    votes: 120859,
    gross: 477
  },
  {
    name: 'Toy Story 4',
    contentRating: 'U',
    duration: 100,
    starRating: 7.8,
    votes: 187391,
    gross: 434
  },
  {
    name: 'Captain Marvel',
    contentRating: '12A',
    duration: 123,
    starRating: 6.9,
    votes: 420459,
    gross: 427
  },
  {
    name: 'Spider-Man: Far From Home',
    contentRating: '12A',
    duration: 129,
    starRating: 7.5,
    votes: 301963,
    gross: 391
  },
  {
    name: 'Aladdin',
    contentRating: 'PG',
    duration: 128,
    starRating: 7.0,
    votes: 213479,
    gross: 356
  },
  {
    name: 'Joker',
    contentRating: '15',
    duration: 122,
    starRating: 8.5,
    votes: 840556,
    gross: 335
  },
  {
    name: 'Jumanji: The Next Level',
    contentRating: '12A',
    duration: 123,
    starRating: 6.7,
    votes: 163288,
    gross: 317
  },
];

const divWidth = document.getElementById('movielist').clientWidth / 2 - 10
const divHeight = (document.getElementById('movielist').clientHeight - 40) / 5

movieData.forEach(movie => {
  movie.color = `rgb(${Math.random() * 255}, ${Math.random() * 255}, ${Math.random() * 255})`
})

const movieList = d3.select('#movielist')
for(let i = 0; i < movieData.length; i++) {
  movieList.append('div')
}

movieList.selectAll('div')
  .select((d, i, n) => {
    d3.select(n[i])
      .style('width', divWidth + 'px')
      .style('height', divHeight + 'px')
      .style('line-height', divHeight + 'px')
      .attr('class', 'movieselect')
    n[i].innerText = movieData[i].name
  })

document.querySelector('#movielist').addEventListener('click', e => {
  const movie = e.target.innerText
  const movieObj = searchMovie(movie)
  d3.select('#moviepost')
    .html(`
    <h2>${movieObj.name.toUpperCase()}</h2>
    <p>Content Rating: <span>${movieObj.contentRating}</span>
    <p>Duration(minutes): <span>${movieObj.duration}</span>
    <p>Star rating(out of 10): <span>${movieObj.starRating}</span>
    <p>Total Votes: <span>${movieObj.votes}</span>
    <p>Gross Colections(USD Mn): <span>${movieObj.gross}</span>
    `)
})

const searchMovie = (movie) => {
  for(let key in movieData) {
    if(movieData[key].name === movie) {
      return movieData[key]
    }
  }
}

document.querySelector('#choicesubmit').addEventListener('submit', (event) => {
  event.preventDefault()
  const choiceMap = new Map()
  choiceMap.set('U', d3.select('#cbu').property('checked'))
  choiceMap.set('15', d3.select('#cb15').property('checked'))
  choiceMap.set('12A', d3.select('#cb12a').property('checked'))
  choiceMap.set('PG', d3.select('#cbpg').property('checked'))

  if(Array.from(choiceMap.values()).includes(true)) {
    document.getElementById('feedback').innerText= ''
    d3.selectAll('#charts').selectAll('div').html(null)
    d3.selectAll('#charts').selectAll('svg').html(null)
    createSelection(choiceMap)
  } else {
    d3.selectAll('#charts').selectAll('div').html(null)
    d3.selectAll('#charts').selectAll('svg').html(null)
    document.getElementById('feedback').innerText = 'Select at least 1 checkbox'
  }
})

const createSelection = (choiceMap) => {
  const selectedMovies = []
  for(let[key, value] of choiceMap) {
    if(value === true) {
      movieData.forEach(movie => {
        if(movie.contentRating === key) {
          selectedMovies.push(movie)
        }
      })
    }
  }

  updateCont(selectedMovies)
  updateLegend(selectedMovies)
  updateGross(selectedMovies)
  updateDura(selectedMovies)
  updateVotes(selectedMovies)
}

const updateCont = (selectedMovies) => {
  let countU = 0
  let count15 = 0
  let count12A = 0
  let countPG = 0

  const uniqueSet = new Set()
  movieData.forEach((movie) => {
    uniqueSet.add(movie.contentRating)
  })
  
  for(let i = 0; i < uniqueSet.size; i++) {
    d3.select('#cont').append('div')
  }

  selectedMovies.forEach(movie => {
    if(movie.contentRating === 'U') {
      countU += 1
    } else if (movie.contentRating === '15') {
      count15 += 1
    } else if (movie.contentRating === '12A') {
      count12A += 1
    } else if (movie.contentRating === 'PG') {
      countPG += 1
    }
  })

  d3.select('#cont div:nth-child(1)')
    .html(`
    <h2>${countU}</h2>
    <p>"U" rating movie(s) selected</p>
    `)
  d3.select('#cont div:nth-child(2)')
    .html(`
    <h2>${count15}</h2>
    <p>"15" rating movie(s) selected</p>
    `)
  d3.select('#cont div:nth-child(3)')
    .html(`
    <h2>${count12A}</h2>
    <p>"12A" rating movie(s) selected</p>
    `)
  d3.select('#cont div:nth-child(4)')
    .html(`
    <h2>${countPG}</h2>
    <p>"PG" rating movie(s) selected</p>
    `)
}

const updateLegend = (selectedMovies) => {
  selectedMovies.forEach(movie => {
    const holder = d3.select('#legend').append('div')
    holder.append('div')
    .style('width', '15px')
    .style('height', '15px')
    .style('background-color', `${movie.color}`)
    holder.append('p').text(`${movie.name}`)
  })
}

const updateGross = (selectedMovies) => {
  selectedMovies.forEach(movie => {
    d3.select('#gross')
      .append('rect')
      .attr('width', `${movie.gross / 2}`)
      .attr('height', '20')
      .attr('x', '0')
      .attr('y', `${selectedMovies.indexOf(movie) * 25 + 25}`)
      .style('fill', `${movie.color}`)
    d3.select('#gross')
      .append('text')
      .text(`${movie.gross}`)
      .attr('x', `${movie.gross / 2 + 5}`)
      .attr('y', `${selectedMovies.indexOf(movie) * 25 + 40}`)
      .style('font-size', '14px')
      .style('fill', 'rgb(63, 63, 63)')
  })
  d3.select('#gross')
  .insert('text','rect')
  .text('Gross collections in USD Million')
  .attr('x' , '0')
  .attr('y', '15')
  .style('font-size', '16')
  .style('font-weight', '600')
  .style('fill', 'rgb(63, 63, 63)')
}

const updateDura = (selectedMovies) => {
  selectedMovies.forEach(movie => {
    d3.select('#dura')
      .append('rect')
      .attr('width', `${movie.duration}`)
      .attr('height', '20')
      .attr('x', '0')
      .attr('y', `${selectedMovies.indexOf(movie) * 25 + 25}`)
      .style('fill', `${movie.color}`)
    d3.select('#dura')
      .append('text')
      .text(`${movie.duration}`)
      .attr('x', `${movie.duration  + 5}`)
      .attr('y', `${selectedMovies.indexOf(movie) * 25 + 40}`)
      .style('font-size', '14px')
      .style('fill', 'rgb(63, 63, 63)')
  })
  d3.select('#dura')
  .insert('text','rect')
  .text('Duration in Minutes')
  .attr('x' , '0')
  .attr('y', '15')
  .style('font-size', '16')
  .style('font-weight', '600')
  .style('fill', 'rgb(63, 63, 63)')
}

const updateVotes = (selectedMovies) => {
  let cxValue = 0
  let xValue = 0

  selectedMovies.forEach(movie => {
    d3.select('#votes')
      .append('circle')
      .attr('r', `${movie.votes / 20000}`)
      .attr('cx', () => {
        cxValue +=  (movie.votes / 20000) + 60
        return cxValue
      })
      .attr('cy', '150')
      .style('fill', `${movie.color}`)
    d3.select('#votes')
      .append('text')
      .text(`${movie.votes}`)
      .attr('text-anchor','middle')
      .attr('x', () => {
        xValue += (movie.votes / 20000) + 60
        return xValue
      })
      .attr('y', `${150 - movie.votes / 20000 - 10}`)
      .style('font-size', '14px')
      .style('fill', 'rgb(63, 63, 63)')
  })
  d3.select('#votes')
    .insert('text', 'circle')
    .text('Number of votes')
    .attr('x', '0')
    .attr('y', '15')
    .style('font-size', '16')
    .style('font-weight', '600')
    .style('fill', 'rgb(63, 63, 63(')
}