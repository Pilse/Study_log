var length = document.querySelectorAll('.comment-item').length;
    for(var i=0;i<length;i++){
    document.querySelectorAll('.comment-item')[i].addEventListener('mouseover',function(event){
         this.querySelector('.UD-btn').classList.remove('hidden');
        
    });
    document.querySelectorAll('.comment-item')[i].addEventListener('mouseout',function(event){
       
            this.querySelector('.UD-btn').classList.add('hidden');
           
    });
}


