const canvas = document.querySelector('#canvas')
const ctx = canvas.getContext('2d')
const decreaseBtn = document.querySelector('.decrease')
const increaseBtn = document.querySelector('.increase')
const clearBtn = document.querySelector('.clear')
const sizeEl = document.querySelector('.size')
const colorEl =document.querySelector('.toolbox input')

let size = 10
let color = 'black'
let isClicked = false
let x
let y

function drawCircle (x, y) {
    ctx.beginPath()
    ctx.fillStyle = color
    ctx.arc(x, y, size, 0, Math.PI * 2)
    ctx.fill()
}
function drawLine (x1, y1 ,x2, y2) {
    ctx.beginPath()
    ctx.moveTo(x1, y1)
    ctx.lineTo(x2, y2)
    ctx.strokeStyle = color
    ctx.lineWidth = size * 2
    ctx.stroke()
}

function updateSize() {
    sizeEl.innerHTML=`${size}`
}


canvas.addEventListener('mousedown',(event)=>{
    isClicked = true
    x = event.offsetX
    y = event.offsetY
    drawCircle(x,y)
})
canvas.addEventListener('mousemove',(event)=>{
    const x1 = event.offsetX
    const y1 = event.offsetY

    if(isClicked){
        drawCircle(x,y)
        drawLine(x,y,x1,y1)
    }
    x=x1
    y=y1
})
canvas.addEventListener('mouseup',(event)=>{
    isClicked = false
})

increaseBtn.addEventListener('click',()=>{
    size++
    if(size>50){
        size=50
    }
    updateSize()
})

decreaseBtn.addEventListener('click',()=>{
    size--
    if(size<5){
        size=5
    }
    updateSize()
})

colorEl.addEventListener('change',(event)=>{
    color = event.target.value
})

clearBtn.addEventListener('click',()=>{
    ctx.clearRect(0,0,canvas.width,canvas.height)
})
