const express = require('express');
const bodyParser = require('body-parser');
const ejs = require('ejs');
const mongoose = require('mongoose');

const app  = express();

app.use(bodyParser.urlencoded({extended:true}));
app.use(express.static('public'));
app.set('view engine','ejs');

mongoose.connect('mongodb://localhost:27017/wikiDB',{ useNewUrlParser: true ,useUnifiedTopology: true});

const wikiSchema = {
    title : String,
    content : String
};

const Article = mongoose.model('article',wikiSchema);

app.route('/articles')

.get(function(req,res){
    Article.find({},function(err,articles){
        if(!err)
            res.send(articles);
        else
            res.send(err);
    });
})

.post(function(req,res){
    const newArticle = new Article({
        title : req.body.title,
        content : req.body.content
    });
    newArticle.save(function(err){
       if(!err)
           res.send('Success');
       else
           res.send(err);
    });
})

.delete(function(req,res){
    Article.deleteMany({},function(err){
        if(!err)
            res.send('Success');
        else
            res.send(err);
    });
});

app.route('/articles/:title')

.get(function(req,res){
    Article.find({title:req.params.title},function(err,articles){
        if(err)
            res.send(err);
        else{
            if(articles)
                res.send(articles);
            else
                res.send('Nothing is found');
        }
    });
})

.put(function(req,res){
    Article.updateOne(
        {title: req.params.title},{$set:{title: req.body.title, content: req.body.content}},function(err){
        if(!err)
            res.send('Success');
        else
            res.send(err);
    });
})

.patch(function(req,res){
    Article.updateOne(
        {title: req.params.title},{$set:req.body},function(err){
        if(!err)
            res.send('Success');
        else
            res.send(err);
    });
})

.delete(function(req,res){
    Article.findOneAndDelete({title:req.params.title},function(err){
        if(!err)
            res.send('Success');
        else
            res.send(err);
    });
});


app.listen(3000,function(){
    console.log('Server started on port 3000');
})

