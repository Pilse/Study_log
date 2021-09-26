// Lines

let point1 = [0, 10]
let point2 = [400, 10]

d3.select('#svg1')
  .append('line')
  .attr('x1', point1[0])
  .attr('y1', point1[1])
  .attr('x2', point2[0])
  .attr('y2', point2[1])
  .style('stroke', 'black')

d3.select('#svg1')
  .append('g')
  .attr('id', 'line1')
  .selectAll('line')
  .data([point1, point2])
  .join('line')

let linePoints = d3.merge([point1, point2])

d3.select('#svg1 #line1')
  .selectAll('line')
  .data([linePoints])
  .join('line')
  .attr('x1', d => d[0])
  .attr('y1', d => d[1])
  .attr('x2', d => d[2])
  .attr('y2', d => d[3])
  .attr('stroke', 'red')

linePoints = [[0, 40, 200, 40],[200, 40, 400 ,40]]

d3.select('#svg1')
  .append('g')
  .attr('id', 'line2')
  .selectAll('line')
  .data(linePoints)
  .join('line')
  .attr('x1', d => d[0])
  .attr('y1', d => d[1])
  .attr('x2', d => d[2])
  .attr('y2', d => d[3])
  .style('stroke', 'gray')

let points = [
  [0, 80],
  [100, 100],
  [200, 60],
  [300, 80],
  [400, 70]
]

let modifiedPoints = d3.pairs(points)

d3.select('#svg1')
  .append('g')
  .attr('id','lineElements')
  .selectAll('line')
  .data(modifiedPoints)
  .join('line')
  .attr('x1', d => d[0][0])
  .attr('y1', d => d[0][1])
  .attr('x2', d => d[1][0])
  .attr('y2', d => d[1][1])
  .style('stroke', (d, i) => d3.schemeCategory10[i])
  .style('stroke-width', 5)

let data2 = [
  [0, 200],
  [70, 150],
  [190, 220],
  [230, 320],
  [320, 200],
  [400, 300],
]

d3.select('#svg1')
  .append('g')
  .attr('id', 'path')
  .selectAll('path')
  .data([data2])
  .join('path')
  .attr('d', d3.line(d => d[0], d => d[1]))
  // .attr('d', d3.line(d => d, d => d))
  .style('stroke', 'blue')
  .style('fill', 'none')

let lineGen = d3.line().curve(d3.curveBasis)
let linePath = lineGen(data2)

d3.select('#svg1')
  .transition(d3.easeQuadOut())
  .duration(3000)
  .attr('width', '100vw')

d3.select('#svg1')
  .append('g')
  .attr('id', 'path')
  .selectAll('path')
  .data([linePath])
  .join('path')
  .attr('d', d => d)
  // .attr('d', d3.line(d => d, d => d))
  .style('stroke', 'red')
  .style('stroke-width', '3')
  .style('fill', 'none')

  // Radial

let radialLine = d3.lineRadial()

// needs angle and radius
data1 = [
  [0, 50],
  [35, 100],
  [80, 150],
  [150, 110],
  [210, 170],
  [210, 90]
]

let radialPathData = radialLine(data1)

d3.select('#svg2')
  .append('g')
  .attr('id', 'chart1')
  .selectAll('path')
  .data([radialPathData])
  .join('path')
  .attr('d', d => d)
  .style('stroke', 'black')
  .style('fill', 'none')

data2 = [
  [0, 50],
  [30, 50],
  [60, 50],
  [90, 50],
  [120, 50],
  [150, 50],
  [180, 50],
  [210, 50],
  [240, 50],
  [270, 50],
  [300, 50],
  [330, 50],
  [360, 50]
]

d3.select('#svg2')
  .append('g')
  .attr('transform', 'translate(200, 200)')
  .attr('id', 'chart2')
  .selectAll('path')
  .data([data2])
  .join('path')
  .attr('d', d3.lineRadial()
    .angle(d => d[0] * (Math.PI / 180))
    .radius(d => d[1] * 2)
    // .curve(d3.curveCatmullRom.alpha(0.5))
  )
  .style('stroke', 'blue')
  .style('fill', 'none')

d3.select('#chart2')
  .append('circle')
  .attr('cx', 0)
  .attr('cy', 0)
  .attr('r', 4)