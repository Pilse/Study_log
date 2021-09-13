let planetData = [
  {
    name: 'Mercury',
    diameter: 4879,
    density: 5427,
    color: 'green'
  },
  {
    name: 'Venus',
    diameter: 12104,
    density: 5243,
    color: 'purple'
  },
  {
    name: 'Earth',
    diameter: 12756,
    density: 5514,
    color: 'dodgerblue'
  },
  {
    name: 'Mars',
    diameter: 6792,
    density: 3933,
    color: 'indianred'
  },
  {
    name: 'Jupiter',
    diameter: 142984,
    density: 1326,
    color: 'gold'
  },
  {
    name: 'Saturn',
    diameter: 120536,
    density: 687,
    color: 'navy'
  },
  {
    name: 'Uranus',
    diameter: 51118,
    density: 1271,
    color: 'thistle'
  },
  {
    name: 'Neptune',
    diameter: 49528,
    density: 1638,
    color: 'pink'
  },
  {
    name: 'Pluto',
    diameter: 2370,
    density: 2095,
    color: 'brown'
  }
];

d3.select('#diameter svg')
  .attr('width', '100%')
  .attr('height', '350')

d3.select('#density svg')
  .attr('width', '100%')
  .attr('height', '350')

let selOrder = 'ascending'

document.querySelector('#btn').addEventListener('click', () => {
  if(selOrder === 'ascending') {
    document.getElementById('msg').innerText = `${selOrder.toUpperCase()} ORDER SELECTED`
    setTimeout(() => {
      document.getElementById('msg').innerText = ''
    },1500)

    genDiameterChart(selOrder)
    genDensityChart(selOrder)

    selOrder = 'descending'
  } else if(selOrder === 'descending'){
    document.getElementById('msg').innerText = `${selOrder.toUpperCase()} ORDER SELECTED`
    setTimeout(() => {
      document.getElementById('msg').innerText = ''
    },1500)

    genDiameterChart(selOrder)
    genDensityChart(selOrder)

    selOrder = 'ascending'
  }
})

const genDiameterChart = (order) => {
  let cxValue = 0

  const diaP = d3.select('#diameter p')
    .text(`Diameter of the planets in kilometer, sorted in ${order} order`)
    .attr('class', 'text')

  const diaSvg = d3.select('#diameter svg')
    .selectAll('circle')
    .data(planetData, data => data.name)
    .join('circle')
    .sort((a, b) => {
      return order === 'ascending' ? 
        a.diameter - b.diameter :
        b.diameter - a.diameter
    })
    .attr('r', data => data.diameter / 1000)
    .attr('cy', '150')
    .attr('cx', (data, idx, nodes) => {
      if(idx === 0) {
        cxValue = data.diameter / 1000
      } else {
        prevRadius = Number(d3.select(nodes[idx - 1]).attr('r'))
        cxValue += prevRadius + data.diameter / 1000
      }
      return (75 * (idx + 1)) + cxValue
    })
    .style('fill', data => data.color)

    const diaText = d3.select('#diameter svg')
      .selectAll('text')
      .data(planetData, data => data.name)
      .join('text')
      .sort((a, b) => {
        return order === 'ascending' ? 
          a.diameter - b.diameter :
          b.diameter - a.diameter
      })
      .attr('x', (data, idx, nodes) => 
        document.querySelectorAll('svg circle')[idx].getAttribute('cx'))
      .attr('y', (data, idx) => idx % 2 === 0 ? '330' : '15')
      .text(data => `${data.name} ${data.diameter}`)
      .style('text-anchor', 'middle')
      .style('fill', 'rgb(63, 63, 63')
      .style('font-size', '13')
      .style('font-weight', 'bold')
}

const genDensityChart = (order) => {
  d3.select('#density p')
    .text(`Density of the planets in kilogram per meter cube, sorted in ${order} order`)
    .attr('class', 'text')

  const denSvg = d3.select('#density svg')
    .selectAll('rect')
    .data(planetData, data => data.name)
    .join('rect')
    .sort((a, b) => order === 'ascending' ?
      a.density - b.density :
      b.density - a.density)
    .attr('width', data => data.density / 10)
    .attr('height', '30')
    .attr('y', (data ,idx) => idx * 40)
    .style('fill', data => data.color)
  
  const denText = d3.select('#density svg')
    .selectAll('text')
    .data(planetData, data => data.name)
    .join('text')
    .sort((a, b) => order === 'ascending' ?
    a.density - b.density :
    b.density - a.density)
    .attr('x', data => data.density / 10 + 20)
    .attr('y', (data, idx) => idx * 40 + 20)
    .text(data => `${data.name}, ${data.density}`)
    .style('text-anchor', 'start')
    .style('fill', 'rgb(63, 63 ,63)')
    .style('font-size', '13')
    .style('font-weight', 'bold')
}