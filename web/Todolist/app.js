const express = require('express');
const bodyParser = require('body-parser');
const mongoose = require('mongoose');
var app = express();
app.use(bodyParser.urlencoded({extended:true}));
app.set('view engine','ejs');
app.use(express.static('public'));


mongoose.connect('',{ useNewUrlParser: true ,useUnifiedTopology: true});
//todo list 
const todolistSchema = {
    todoListItem : String
};

const Todoist = new mongoose.model('todolist',todolistSchema);

const baekjoon = new Todoist({
    todoListItem: 'Study'
});
const udemy = new Todoist({
    todoListItem: 'Work'
});
const game = new Todoist({
    todoListItem: 'Exercise'
});

var defaultLists = [baekjoon,udemy,game];


app.get('/',function(req,res){

    var today = new Date(); 
    var options = {
        weekday:'long',
        day:'numeric',
        month:'long'
    };
    var day = today.toLocaleDateString('en-US',options);

    Todoist.find({},function (err, todolists) {
        if (todolists.length === 0) {
            Todoist.insertMany(defaultLists,function(err){
                if(err)
                    console.log(err);
            });
            res.redirect('/');
            
        }
        else
            res.render('list',{kindOfDay: day, newTodoList: todolists});
    });
    
});

app.post('/',function(req,res){
    const newTodo = new Todoist({
        todoListItem : req.body.todo
    });
    newTodo.save();
    res.redirect('/'); 
})

app.get('/about',function(req,res){
    res.render('about');
    res.send(__dirname+'/views.about.ejs');
})

app.post('/delete',function(req,res){   
    Todoist.deleteOne({todoListItem: req.body.delete},function(err){
        if(err)
            console.log(err);
    });
    res.redirect('/');
});



app.listen(process.env.PORT || 3000, function(){
    console.log('Server has started');
});
