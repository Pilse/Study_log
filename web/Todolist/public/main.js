var length = document.querySelectorAll('.item').length;
for(var i=0;i<length;i++){
    document.querySelectorAll('.item')[i].addEventListener('mouseover',function(event){
        this.querySelector('.delete').classList.remove('hidden');
    });
    document.querySelectorAll('.item')[i].addEventListener('mouseout',function(event){

        this.querySelector('.delete').classList.add('hidden');
    });
}
