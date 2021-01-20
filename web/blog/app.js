const express = require('express');
const bodyParser = require('body-parser');
const _ = require('lodash');

var app = express();
app.use(express.static('public'));
app.use(bodyParser.urlencoded({ extended: true }));
app.set('view engine', 'ejs');

var postComment = [];
var homeContent = [];
var aboutContent = `Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.`
var contactContent = 'mail: gogosky1175@gmail.com'


app.get('/',function(req,res){
    
    res.render('home',{home: homeContent});
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
    var post={
        title : req.body.composeTitle,
        body : req.body.composeText,
        shortBody : req.body.composeText.substring(0,100)+'...'
    }
    homeContent.push(post);
    res.redirect('/');
});

app.get('/posts/:title',function(req,res){
    homeContent.forEach(function(content){
        console.log(postComment);
        if(_.lowerCase(content.title)===_.lowerCase(req.params.title))
            res.render('post',{post: content, comment:postComment});
    });
});

app.post('/comment/:title',function(req,res){
    var title = req.params.title;
    var comment = {
        body: req.body.comment,
        commentTitle: title
    }
    postComment.push(comment);
    console.log(comment);
    res.redirect(`/posts/${title}`);
})



app.listen(3000,function(req,res){
    console.log('Server is started on port 3000');
});