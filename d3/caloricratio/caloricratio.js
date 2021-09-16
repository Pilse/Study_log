const dryFruitData = [
  {
    name: 'Almonds',
    carbs: 15,
    fats: 72,
    proteins: 13
  },
  {
    name: 'Raisins',
    carbs: 96,
    fats: 1,
    proteins: 3
  },
  {
    name: 'Cashews',
    carbs: 23,
    fats: 66,
    proteins: 11
  },
  {
    name: 'Walnuts',
    carbs: 9,
    fats: 83,
    proteins: 8
  },
  {
    name: 'Apricots',
    carbs: 93,
    fats: 2,
    proteins: 5
  },
  {
    name: 'Pistachios',
    carbs: 20,
    fats: 67,
    proteins: 13
  },
  {
    name: 'Figs',
    carbs: 94,
    fats: 3,
    proteins: 3
  },
  {
    name: 'Dates',
    carbs: 98,
    fats: 0,
    proteins: 2
  },
  {
    name: 'Prunes',
    carbs: 96,
    fats: 1,
    proteins: 3
  },
  {
    name: 'Hazelnuts',
    carbs: 11,
    fats: 81,
    proteins: 8
  },
];

const svgWidth = d3.select('#chart').node().clientWidth
const svgHeight = d3.select('#chart').node().clientHeight

let svg = d3.select('#chart')
svg.attr('viewBox', `0 ${-svgHeight} ${svgWidth} ${svgHeight}`)

let allGs = svg.selectAll('g')
  .data(dryFruitData)
  .join('g')

allGs.each((data, idx, nodes) => {
  const gElement = d3.select(nodes[idx])
  const stack = (ele, split) => {
    let height = 0
    const bar = ele.selectAll('rect')
      .data(split)
      .join('rect')
      .attr('width', svgWidth / 21)
      .attr('height', data => data * 5)
      .attr('rx', '3')
      .attr('ry', '3')
      .attr('x', svgWidth / 21 +(idx * (2 * svgWidth / 21)))
      .attr('y', (data, idx) => {
        height = height + split[idx]
        return (-height * 5)
      })
      .style('fill', (data, idx) => idx === 0 ? 'burlywood' : idx === 1 ? 'sandybrown' : 'navajowhite')

    ele.selectAll('text')
      .data([dryFruitData[idx]])
      .join('text')
      .attr('x', svgWidth / 21 + (idx * (2 * svgWidth / 21)) - 15)
      .attr('y', '-250')
      .style('writing-mode', 'tb')
      .style('text-anchor', 'middle')
      .text(data => `${data.name} (${data.carbs}, ${data.fats}, ${data.proteins})`)
      .style('fill', '#eee')
      .style('font-weight', '500')

  }
  gElement.call(stack, [data.carbs, data.fats, data.proteins])
})