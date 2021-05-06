const elements = document.querySelectorAll('.element');
const main = document.querySelector('.main');
const container = document.body;

let dragged;
let d;
let y;
let x;
function s(e){
    y = e.pageY;
    x = e.pageX;
    d.style.top = (y-50)+"px";
    d.style.left = (x-30)+"px";
}

elements.forEach(element => {
  
    element.addEventListener('mousedown', (e)=> {
        dragged = e.target;
        d = dragged.cloneNode(1);
        d.style.opacity = 0.5;
        d.style.position = "absolute";
        d.style.top = y+"px";
        d.style.left = x+"px";
        container.appendChild(d);
        
        container.addEventListener("mousemove",s)
        container.addEventListener("mouseup",()=>{
            container.removeEventListener("mousemove",s,false);
            d.style.opacity = 1;
        })
    });
   
}
)








