const hour = document.querySelector('.hour');
const minute = document.querySelector('.minute');
const second = document.querySelector('.second');
const theme = document.querySelector('.theme');
const date = document.querySelector('.info .date');
const times = document.querySelector('.time');
const html = document.querySelector('html');

const days = ['Monday','Tuesday','Wednesday','Thursday','Friday','Saturday','Sunday'];
const month = ['January','February','March','April','May','June','July','August','September','October','November','December']

setTime();

function setTime() {
    const day = new Date();
    const time = Math.floor(new Date().getTime()/1000);

    const curHour = time/3600+9;
    const curMinute = time/60;
    const curDay = day.getDay();
    const curMonth = day.getMonth();
    const curDate = day.getDate();
    
    second.style.transform = `translate(-50%, -100%) rotate(${6*time}deg)`;
    minute.style.transform= `translate(-50%, -100%) rotate(${6*curMinute}deg)`;
    hour.style.transform= `translate(-50%, -100%) rotate(${30*curHour}deg)`;

    date.innerHTML=`<span class="black"> ${days[curDay-1]}</span>, ${month[curMonth]} ${curDate}</div>`
    times.innerHTML=`${Math.floor(curHour%24)}:${Math.floor(curMinute%60)<10? '0'+Math.floor(curMinute%60) : Math.floor(curMinute%60)}`
}

theme.addEventListener('click',()=>{
    if(html.classList.contains('dark')){
        theme.innerHTML=('dark mode');
    } else {
        theme.innerHTML=('light mode');
    }
    html.classList.toggle('dark')
})

setInterval(setTime,1000);