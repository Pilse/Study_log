// Company Data
const indian9IT = [
  {
    name: 'Tata Consultancy Services',
    code: 'tcs',
    revenue: 1524970,
    marketCap: 8453370,
    employees: 420000,
    salesGrowth: 10.47,
    color: 'salmon',
    fb: 730890,
    tw: 439800,
    li: 4639844
  },
  {
    name: 'Infosys',
    code: 'infosys',
    revenue: 873710,
    marketCap: 2820280,
    employees: 228000,
    salesGrowth: 9.81,
    color: 'coral',
    fb: 853447,
    tw: 419100,
    li: 3330921
  },
  {
    name: 'HCL Technologies',
    code: 'hcl',
    revenue: 656430,
    marketCap: 1533700,
    employees: 150000,
    salesGrowth: 24.74,
    color: 'khaki',
    fb: 1415863,
    tw: 438200,
    li: 2042198
  },
  {
    name: 'Wipro',
    code: 'wipro',
    revenue: 601370,
    marketCap: 1530430,
    employees: 160000,
    salesGrowth: 4.82,
    color: 'turquoise',
    fb: 1446866,
    tw: 482100,
    li: 3115578
  },
  {
    name: 'Tech Mahindra',
    code: 'mahindra',
    revenue: 351190,
    marketCap: 701410,
    employees: 125700,
    salesGrowth: 9.45,
    color: 'deepskyblue',
    fb: 131903,
    tw: 122400,
    li: 1629563
  },
  {
    name: 'L & T Infotech',
    code: 'landt',
    revenue: 100140,
    marketCap: 293020,
    employees: 31500,
    salesGrowth: 17.34,
    color: 'violet',
    fb: 59883,
    tw: 141200,
    li: 675820
  },
  {
    name: 'Mphasis',
    code: 'mphasis',
    revenue: 79730,
    marketCap: 177380,
    employees: 22000,
    salesGrowth: 8.33,
    color: 'lightpink',
    fb: 15213,
    tw: 7512,
    li: 313362
  },
  {
    name: 'Mindtree',
    code: 'mindtree',
    revenue: 73750,
    marketCap: 118550,
    employees: 21000,
    salesGrowth: 14.54,
    color: 'mistyrose',
    fb: 57914,
    tw: 82800,
    li: 432892
  },
  {
    name: 'Hexaware Technologies',
    code: 'hexaware',
    revenue: 53060,
    marketCap: 101650,
    employees: 18300,
    salesGrowth: 14.17,
    color: 'navajowhite',
    fb: 68095,
    tw: 9191,
    li: 246766
  }
];

const list = d3.select('#list').selectAll('h3')
list.on('click', (event) => {
  indian9IT.forEach(company => {
    if(event.target.className == company.code) {
      d3.select('#company').html(`Company: <span>${company.name}</span>`)
      d3.select('#revenue').node().innerHTML = `Revenue (INR Mn): <span>${company.revenue.toLocaleString()}</span>`
      d3.select('#marketcap').node().innerHTML = `Market Cap (INR Mn): <span>${company.marketCap.toLocaleString()}</span>`
      d3.select('#employees').node().innerHTML = `Employees (INR Mn): <span>${company.employees.toLocaleString()}</span>`
      d3.select('#salesgrowth').node().innerHTML = `Employees (INR Mn): <span>${company.salesGrowth.toLocaleString()}</span>`

      d3.select('#fb h2').node().innerHTML = 'Facebook'
      d3.select('#fb p').node().innerHTML = `${company.fb}`
      d3.select('#tw h2').node().innerHTML = 'Twitter'
      d3.select('#tw p').node().innerHTML = `${company.tw}`
      d3.select('#li h2').node().innerHTML = 'LinkedIn'
      d3.select('#li p').node().innerHTML = `${company.li}`
    }
  })
})

d3.select('#charts')
  .selectAll('div .chartarea')
  .append('svg')
  .attr('width', '500')
  .attr('height', '450')
  .attr('viewBox', '0 -450 500 450')

const SVGWIDTH = d3.select('svg').attr('width')
const SVGHEIGHT = d3.select('svg').attr('height')

const listCheck = d3.select('#list').selectAll('input')
let checkedValues = []
listCheck.on('click', () => {
  listCheck.each((data, idx ,nodes) => {
    checkedValues[idx] = d3.select(nodes[idx]).property('checked')
  })
  let checkedCompanies = []
  for(let i = 0; i < checkedValues.length; i++) {
    if(checkedValues[i]) {
      checkedCompanies.push(indian9IT[i])
    }
  }
  updateRevenueChart(checkedCompanies)
  updateMarketCapChart(checkedCompanies)
  updateEmployeeChart(checkedCompanies)
  updateGrowthChart(checkedCompanies)
})

const updateRevenueChart = (companies) => {
  if(companies.length === 0) {
    resetTitle('#revenuechart')
    resetChart('#revenuechart')
    resetChartText('#revenuechart')
  } else {
    setTitle('#revenuechart', 'Revenue (INR Mn)')
    setVerticalBars('#revenuechart', companies, 8, 'revenue')
    setVerticalBarText('#revenuechart', companies, 'revenue')
  }
}

const updateMarketCapChart = (companies) => {
  if(companies.length === 0) {
    resetTitle('#marketcapchart')
    resetChart('#marketcapchart')
    resetChartText('#marketcapchart')
  } else {
    setTitle('#marketcapchart', 'Market Cap (INR Mn)')
    setVerticalBars('#marketcapchart', companies, 42, 'marketCap')
    setVerticalBarText('#marketcapchart', companies, 'marketCap')
  }
}

const updateEmployeeChart = (companies) => {
  if(companies.length === 0) {
    resetTitle('#employeechart')
    resetChart('#employeechart')
    resetChartText('#employeechart')
  } else {
    setTitle('#employeechart', 'Employees (INR Mn)')
    setVerticalBars('#employeechart', companies, 3, 'employees')
    setVerticalBarText('#employeechart', companies, 'employees')
  }
}

const updateGrowthChart = (companies) => {
  if(companies.length === 0) {
    resetTitle('#growthchart')
    resetChart('#growthchart')
    resetChartText('#growthchart')
  } else {
    setTitle('#growthchart', 'Sales Growth Rate for 3 years(%)')
    setVerticalBars('#growthchart', companies, 0.0002, 'salesGrowth')
    setVerticalBarText('#growthchart', companies, 'salesGrowth')
  }
}

const setTitle = (seln, title) => {
  d3.select(seln)
    .select('.charttitle')
    .text(title)
}

const resetTitle = (seln) => {
  d3.select(seln)
    .select('.charttitle')
    .html(null)
}

const resetChart = (seln) => {
  d3.select(seln)
    .select('svg')
    .selectAll('rect')
    .remove()
}

const resetChartText = (seln) => {
  d3.select(seln)
    .select(svg)
    .selctAll('text')
    .remove()
}

const setVerticalBars = (seln, companies, factor, parameter) => {
  d3.select(seln)
    .select('svg')
    .selectAll('rect')
    .data(companies)
    .join('rect')
    .each((data, idx, nodes) => {
      const elem = d3.select(nodes[idx])
      elem.attr('x', (SVGWIDTH / (2 * companies.length + 1)) * (2 * idx + 1))
        .attr('y', -data[parameter]/(SVGHEIGHT*factor))
        .attr('width', (SVGWIDTH / (2 * companies.length + 1)))
        .attr('height', data[parameter] / (SVGHEIGHT * factor))
        .style('fill', data.color)
        .attr('rx', '5')
        .attr('ry', '5')
    })
}

const setVerticalBarText = (seln, companies, parameter) => {
  d3.select(seln)
    .select('svg')
    .selectAll('text')
    .data(companies)
    .join('text')
    .each((data, idx, nodes) => {
      const elem = d3.select(nodes[idx])
      elem.attr('x', (SVGWIDTH / (2 * companies.length + 1)) * (2 * idx + 1) - 10)
        .attr('y', '0')
        .text(data => data.code.toUpperCase() + ' | ' + data[parameter].toLocaleString())
        .style('fill', 'darkslategray')
        .style('text-anchor', 'end')
        .style('font-size', '12')
        .style('font-weight', '500')
        .style('writing-mode', 'tb')
    })
}