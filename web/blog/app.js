const express = require('express');
const bodyParser = require('body-parser');
const _ = require('lodash');
const mongoose = require('mongoose');
const mongodb = require('mongodb');

mongoose.connect('mongodb://localhost:27017/blogDB',{ useNewUrlParser: true ,useUnifiedTopology: true})

const postSchema = {
    title : String,
    body : String,
    shortBody : String
};
const commentSchema = {
    postTitle : String,
    body : String 
};

const Post = mongoose.model('post',postSchema);
const Comment = mongoose.model('comment',commentSchema);


var app = express();
app.use(express.static('public'));
app.use(bodyParser.urlencoded({ extended: true }));
app.set('view engine', 'ejs');


var aboutContent = `Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.`
var contactContent = 'gogosky1175@gmail.com'


app.get('/',function(req,res){
    Post.find({},function(err,postLists){
        res.render('home',{home: postLists});
    });
  
});
app.get('/about',function(req,res){
    res.render('about',{aboutParagraph: aboutContent});
});
app.get('/contact',function(req,res){
    res.render('contact',{contactParagraph: contactContent});
});

app.get('/compose',function(req,res){
    res.render('compose');
});

app.post('/compose',function(req,res){
    const post = new Post({
        title : req.body.composeTitle,
        body : req.body.composeText,
        shortBody : req.body.composeText.substring(0,100)+'...'
    });
    post.save();
    res.redirect('/');
});

app.get('/posts/:title', function (req, res) {
    Post.find({}, function (err,posts) {
        posts.forEach(function (post) {
            if (_.lowerCase(post.title) === _.lowerCase(req.params.title)){
                Comment.find({postTitle: post.title},function(err,comments){
                    res.render('post', { post: post, comment: comments });
                });
            }
        });
    });
});

app.post('/comment/:title',function(req,res){
    const comment = new Comment({
        postTitle : req.params.title,
        body: req.body.comment
    });
    comment.save()
    res.redirect(`/posts/${req.params.title}`);
})

app.post('/delete',function(req,res){
    console.log(req.body);
    if(req.body.delete==='comment'){
        Comment.findOneAndDelete({_id:req.body.deleteComment},function(err){
        res.redirect(`/posts/${req.body.title}`);
        });
    }
    else{
        Post.findOneAndDelete({_id:req.body.deletePost},function(err){
            res.redirect('/');
            });
    }
})



app.listen(3000,function(req,res){
    console.log('Server is started on port 3000');
});