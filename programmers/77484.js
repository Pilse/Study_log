function solution(lottos, win_nums) {
  const zeros = lottos.filter(num => num == 0).length
  let correctNumCnt = 0
  let minRank = 6
  
  for(let i = 0; i < 6; i++) {
      if(win_nums.includes(lottos[i]))  {
          correctNumCnt ++
      }
  }
  
  if(correctNumCnt >= 2) {
      minRank = 7 - correctNumCnt
  }
  
  const maxRank = Math.max(1, minRank - zeros)
  
  const answer = [maxRank, minRank];
  return answer;
}