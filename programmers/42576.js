function solution(participant, completion) {
  const map = new Map()
  let answer
  
  completion.forEach(c => {
      if(map.has(c)) {
          map.set(c, map.get(c) + 1)
      } else {
          map.set(c, 1)
      }
  })
  
  participant.forEach(p => {
      if(map.has(p)) {
          if(map.get(p) == 1) {
              map.delete(p)
          } else {
              map.set(p, map.get(p) - 1)
          }
      } else {
          answer = p
      }
  })
  return answer;
}