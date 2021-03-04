const goodEl = document.querySelector('#good');
const cheapEl = document.querySelector('#cheap');
const fastEL = document.querySelector('#fast');
const togglesEl = document.querySelectorAll('.toggle');

togglesEl.forEach(toggle=>{
    toggle.addEventListener('change',(e)=>{
        if(goodEl.checked && cheapEl.checked && fastEL.checked) {
            if(goodEl === e.target) {
                fastEL.checked = false;
            }
            if(cheapEl === e.target) {
                goodEl.checked = false;
            }
            if(fastEL === e.target) {
                cheapEl.checked = false;
            }
        }
    })
})