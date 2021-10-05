process.env.UV_THREADPOOL_SIZE = 1
const cluster = require('cluster')

// 파일이 master mode에서 실행되는지 확인
if(cluster.isMaster) {
  // child(slave) 모드 indes.js를 생성
  // 서버컴퓨터의 논리적 코어(cpu * threads) 수만큼 child(slave)를 생성하는 것을 권장
  cluster.fork()
  cluster.fork()
  cluster.fork()
  cluster.fork()
  cluster.fork()
  cluster.fork()
} else {
  // child(slave) 모드로서 서버 실행
  const express = require('express')
  const crypto = require('crypto')

  const app = express()

  app.get('/', (req, res) => {
    crypto.pbkdf2('a', 'b', 100000, 512, 'sha512', () => {
      res.send('Hi there')
    }) 
  })

  app.get('/fast', (req, res) => {
    res.send('This was fast!')
  })
    
  app.listen(3000)
}


// ---------------- 성능확인 벤치마크 ----------------
// $ ab -c 50 - n 500 localhost:3000/fast
// -c 50 -> 동시에 50개의 요청
// -n 500 -> 500번
