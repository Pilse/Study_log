const express = require('express');
const bodyParser = require('body-parser');
const { response } = require('express');
const { URITooLong } = require('http-errors');
const { toLocaleString } = require('methods');
const { runInNewContext } = require('vm');
var app = express();
app.use(bodyParser.urlencoded({extended:true}));
app.set('view engine','ejs');
app.use(express.static('public'));

var items =[];
var todoListCount = items.length;

app.get('/',function(req,res){

    var today = new Date();
    
    var options = {
        weekday:'long',
        day:'numeric',
        month:'long'
    };
    var day = today.toLocaleDateString('en-US',options);
   
    res.render('list',{kindOfDay: day, newTodoList: items, length: todoListCount});
    res.send(__dirname+'/views/list.ejs');
    
});

app.post('/',function(req,res){
    var newTodo = req.body.todo;
    items.push(newTodo);
    res.redirect('/'); 
})

app.get('/about',function(req,res){
    res.render('about');
    res.send(__dirname+'/views.about.ejs');
})



app.listen(3000,function(){
    console.log('Server started on port 3000');
});