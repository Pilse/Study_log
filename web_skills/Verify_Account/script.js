const codes = document.querySelectorAll('.code');
const btn = document.querySelector('button');

function isAllValid() {
    let flag = true;

    codes.forEach(code=>{
        if(code.value==='') {
            flag = false;
        }
    })
    if(flag) {
        btn.style.backgroundColor = 'skyblue';
        btn.style.cursor = 'pointer'
    } else {
        btn.style.backgroundColor = '';
        btn.style.cursor = 'not-allowed'
    }
}

codes.forEach((code,idx)=>{
    code.addEventListener('keydown',(e)=>{
        if(e.key>=0 && e.key<10) {
            if(idx + 1 !== codes.length)
                setTimeout(()=>codes[idx + 1].focus(),10);
        }
        setTimeout(()=>isAllValid(),30);
    })
});