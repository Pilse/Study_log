const express = require('express');
const bodyParser= require('body-Parser');
const ejs = require('ejs');
const session = require('express-session');
const passport = require('passport');
const LocalStrategy = require('passport-local').Strategy;
const GoogleStrategy = require('passport-google-oauth20').Strategy;
const mongoose = require('mongoose');
const flash = require('connect-flash');
const passportLocalMongoose = require ('passport-local-mongoose');
const bcrypt = require('bcrypt');
require('dotenv').config();

const saltRounds = 10;

const app = express();
mongoose.connect('mongodb://localhost:27017/userDB',{ useNewUrlParser: true, useUnifiedTopology: true });

const userSchema = new mongoose.Schema({
    username: String,
    password: String,
    googleId: String,
    secret: String
});
userSchema.plugin(passportLocalMongoose);

const User = new mongoose.model('user',userSchema);


app.use(bodyParser.urlencoded({extended: true}));
app.use(express.static('public'));
app.use(session({
    secret:'secret',
    resave: false,
    saveUninitialized: true
}));
app.use(flash());
app.use(passport.initialize());
app.use(passport.session());
app.set('view engine','ejs');

passport.serializeUser(function(user,done){
    console.log(user.id);
    done(null,user.id);
});
passport.deserializeUser(function(id,done){
    User.findById(id,function(err,user){
        console.log(user);
        done(err,user);
    })
});
passport.use(new LocalStrategy(
    function (username, password, done) {
        User.findOne({ username: username }, function (err, user) {
            if (err) { return done(err); }
            if (!user) {
                return done(null, false, { message: 'Incorrect username.' });
            }
            bcrypt.compare(password,user.password,function(err,isSame) {
                if(!isSame)
                    return done(null, false, { message: 'Incorrect password.' });
                else
                    return done(null, user);
            })
        });
    }));

passport.use(new GoogleStrategy({
    clientID: process.env.CLIENT_ID,
    clientSecret: process.env.CLIENT_SECRET,
    callbackURL: "http://localhost:3000/auth/google/secrets",
    userProfileURL:'https://www.googleapis.com/oauth2/v3/userinfo'
},
    function (accessToken, refreshToken, profile, cb) {
        User.findOne({googleId: profile.id},function(err,user){
            if(err)
                return cb(err);
            else{
                if(!user){
                    const user = new User({
                        username: profile.displayName,
                        googleId: profile.id
                    });
                    user.save();
                    return cb(null,user);
                }
                else
                    return cb(null,user);
            }
        });
    }
));
app.get('/', function (req, res) {
    res.render('home');
});

app.get('/login', function (req, res) {
    res.render('login');
});

app.get('/register', function (req, res) {
    res.render('register');
});

app.get('/secrets', function (req, res) {
    if (req.isAuthenticated()) {
        User.find({secret:{$ne:null}},function(err,foundUser){
            if(err)
                console.log(err);
            else{
                if(foundUser)
                    res.render('secrets',{userSecrets:foundUser});
            }
        })
    }
    else {
        res.redirect('/login');
    }
});
app.get('/logout', function (req, res) {
    req.logout();
    res.redirect('/');
});

app.get('/auth/google',
  passport.authenticate('google', { scope: ['profile'] }));

app.get('/auth/google/secrets', 
  passport.authenticate('google', { failureRedirect: '/login' }),
  function(req, res) {
    res.redirect('/secrets');
  });

app.get('/submit',function(req,res){
    if(req.isAuthenticated())
        res.render('submit');
    else
        res.redirect('/login');
});

app.post('/submit',function(req,res){
    const submittedSecret = req.body.secret;
    User.findById(req.user.id,function(err,usr){
        if(err)
            console.log(err);
        else{
            if(usr){
                usr.secret=submittedSecret;
                usr.save(function(){
                    res.redirect('/secrets');
                })
            }
        }
    })
});

app.post('/login',passport.authenticate('local',{
    successRedirect:'/secrets',
    failureRedirect: '/login',
    failureFlash: true
}));

app.post('/register', function (req, res) {
  bcrypt.hash(req.body.password, saltRounds , function(err,hash){
    const user = new User({
        username : req.body.username,
        password: hash
    });
    user.save(function(err){
        if(err) console.log(err);
        else{
            req.flash('message','now you can login');
            res.redirect('/login');
        }
    });
  });


});

app.listen(3000,function(){
    console.log('Server started on port 3000');
});
