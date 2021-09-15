let fordData = [
  {
    quarter: 'Q1',
    year: 2018,
    truck: 109276,
    suv: 82395,
    car: 52635
  },
  {
    quarter: 'Q2',
    year: 2018,
    truck: 100683,
    suv: 84617,
    car: 45335
  },
  {
    quarter: 'Q3',
    year: 2018,
    truck: 93408,
    suv: 66884,
    car: 37112
  },
  {
    quarter: 'Q4',
    year: 2018,
    truck: 106599,
    suv: 79225,
    car: 34950
  },
  {
    quarter: 'Q1',
    year: 2019,
    truck: 278898,
    suv: 213086,
    car: 98265
  },
  {
    quarter: 'Q2',
    year: 2019,
    truck: 324243,
    suv: 215898,
    car: 110195
  },
  {
    quarter: 'Q3',
    year: 2019,
    truck: 309920,
    suv: 193100,
    car: 77231
  },
  {
    quarter: 'Q4',
    year: 2019,
    truck: 330075,
    suv: 208387,
    car: 63400
  }
];

let years = new Set()
fordData.forEach(d => {
  years.add(d.year)
})

let yearlyData = []
years = Array.from(years)

years.forEach(year => {
  let yearSum = 0
  fordData.forEach(d => {
    if(d.year === year) {
      yearSum += d.truck + d.suv + d.car
    }
  })
  yearlyData.push(yearSum)
})

d3.select('#gen-info').on('click', (event, data) => {
  document.getElementById('gen-info').disabled = true

  d3.select('#years p')
    .text('Number of Vehicles')

  const yearSvg = d3.select('#years svg').selectAll('rect')
  yearSvg.data(yearlyData)
    .join('rect')
    .attr('x', '0')
    .attr('y', (data, idx) => {
      return document.querySelector('#years svg').clientHeight / 4 * (idx + 1)
    })
    .attr('height', (data, idx) => {
      return document.querySelector('#years svg').clientHeight / 4 - 5
    })
    .attr('width', data => data / 10000)
    .attr('id', (data, idx) =>`${years[idx]}`)
    .style('fill', (data, idx) => {
      if(idx == 0) {
        return 'steelblue'
      } else {
        return 'dodgerblue'
      }
    })
    .style('cursor', 'pointer')

  yearSvg.data(yearlyData)
    .join('text')
    .attr('x', data => data / 10000 + 10)
    .attr('y', (data, idx) => 
      document.querySelector('#years svg').clientHeight / 4 * (idx + 1) + (document.querySelector('#years svg').clientHeight / 4) / 2
    )
    .text((data, idx) => `${years[idx]} - ${data}`)
    .style('font-size', '12')
    .style('font-weight', '500')
    .style('fill', 'gray')

  d3.select('#quarters p')
    .text('Click on a year bar for more details')

  d3.select('#years')
    .selectAll('rect')
    .on('click', (event, data) => {
      d3.select('#quarters p')
        .text(`${event.target.id}: Quarterly Break-Up`)
      
      let quarterlyData = []
      fordData.forEach(data => {
        if(event.target.id === data.year.toString()) {
          quarterlyData.push(data)
        }
      })

      const quarterSvg = d3.select('#quarters svg').selectAll('rect')
      quarterSvg.data(quarterlyData)
        .join('rect')
        .attr('x', '0')
        .attr('y', (data, idx) => document.querySelector('#years svg').clientHeight / 6 * (idx + 1))
        .attr('height', () => document.querySelector('#years svg').clientHeight / 6 -5)
        .attr('width', data => (data.truck + data.suv + data.car) / 1500)
        .attr('id', data => `${data.quarter}`)
        .style('fill', 'skyblue')
        .style('cursor', 'pointer')
      
      d3.select('#quarters svg')
        .selectAll('text')
        .data(quarterlyData)
        .join('text')
        .attr('x', data => (data.truck + data.suv + data.car) / 1500 + 10)
        .attr('y', (data, idx) => document.querySelector('#quarters svg').clientHeight / 6 * (idx + 1) + (document.querySelector('#quarters svg').clientHeight / 6) / 2)
        .text((data, idx) => `${data.quarter} - ${data.truck + data.suv + data.car}`)
        .style('font-size', '12')
        .style('font-weight', '500')
        .style('fill', 'gray')

      d3.select('#vehicles p')
        .text('Hover on a quarter bar for vehicle types')
      
      d3.select('#quarters svg')
        .selectAll('rect')
        .on('mouseover', (event, data) => {
          d3.select('#vehicles p')
            .text(`${data.year} | ${data.quarter}: Vehicle Type Break-Up`)
          d3.select('#vehicles svg')
            .selectAll('rect')
            .data([data.truck, data.suv, data.car])
            .join('rect')
            .attr('width', data => data / 1000)
            .attr('height', () => document.querySelector('#vehicles svg').clientHeight / 5 - 5)
            .attr('x', '0')
            .attr('y', (data, idx) => document.querySelector('#vehicles svg').clientHeight / 5 * (idx + 1))
            .style('fill', (data, idx) => {
              if(idx === 0) {
                return '#38acec'
              }
              if(idx === 1) {
                return '#79baec'
              }
              else {
                return '#a0cfec'
              }
            })
            d3.select('#vehicles svg')
              .selectAll('text')
              .data([data.truck, data.suv, data.car])
              .join('text')
              .attr('x', data => data / 1000 + 10)
              .attr('y', (data, idx) => document.querySelector('#vehicles svg').clientHeight / 5 * (idx + 1) + (document.querySelector('#vehicles svg').clientHeight / 5) / 2)
              .text((data, idx) => {
                if(idx === 0) {
                  return 'Truck | ' + data
                }
                if(idx === 1) {
                  return 'SUV | ' + data
                }
                else {
                  return 'Cars | ' + data
                }
              })
              .style('font-size', '12')
              .style('font-weight', '500')
              .style('fill', 'gray')
        })
    })
})