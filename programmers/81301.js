function solution(s) {
  const stringToNumber = {
      "zero" : '0',
      "one" : '1',
      "two" : '2',
      "three" : '3',
      "four" : '4',
      "five" : '5',
      "six" : '6',
      "seven" : '7',
      "eight" : '8',
      "nine" : '9',
  }
  
  let answer = s
  
  Object.keys(stringToNumber)
      .forEach(numString => {
      const regex = new RegExp(`${numString}`,'g')
      answer = answer.replace(regex, stringToNumber[numString])
  })
  
  return Number(answer);
}