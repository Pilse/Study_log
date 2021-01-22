const mongoose = require('mongoose');
//create database
mongoose.connect('mongodb://localhost:27017/fruitsDB',{ useNewUrlParser: true ,useUnifiedTopology: true});
//create collection
const fruitSchema = new mongoose.Schema({
    name : {
        type:String,
        required:[1,'Fruit name is needed.']
    },
    rating : {
        type:Number,
        min:1,
        max:10
    },
    review : String
});
const Fruit = mongoose.model('Fruit',fruitSchema);

const fruit = new Fruit({
    name: 'Apple',
    rating: 7,
    review: 'Pretty solid as a fruit'
});

const kiwi = new Fruit({
    name: 'Kiwi',
    score: 6,
    review : 'not bad'
});

const orange = new Fruit({
    name : 'Orange',
    score: 7,
    review: 'not bad'
});

const banana = new Fruit({
    name : 'Banana',
    score: 8,
    review : 'best fruit ever'
});
const peach = new Fruit({
    name: 'Peach',
    score: '7',
    review: 'good, but randomly.'
});

const pineapple = new Fruit({
    name: 'Pineapple',
    score: '6',
    review: 'Great, randomly.'
})

const strawberry = new Fruit({
    name: 'Strawberry',
    rating: 7,
    review: 'Sweet, randomly.'
});
strawberry.save();
peach.save();

Fruit.insertMany([kiwi,orange,banana],function(err){
    if(err){
        console.log(err);
    }
    else{
        console.log('success');
    }
});
Fruit.find(function(err,fruits){

    if(err)
        console.log(err);
    else{
        fruits.forEach(function(fruit){
            console.log(fruit.name);
        });
    }
});

Fruit.updateOne({_id: "60095fbee0285225a5b866d3"},{rating: 7 },function(err){

    if(err)
        console.log(err);
    else{
        console.log('Update success');
    }
});

Fruit.deleteOne({name : 'Peach'},function(err){
    if(err)
        console.log(err);
    else{
        console.log('Delete success');
    }
});



const humanSchema = new mongoose.Schema({
    name : String,
    age : Number,
    favouriteFruit : fruitSchema
});

const Human = mongoose.model('human',humanSchema);


const human = new Human({
    name: 'Amy',
    age: 13,
    favouriteFruit : pineapple
});

Human.updateOne({name: 'Amy'},{favouriteFruit: pineapple},function(err){
    if(err){
        console.log(err);
    }
});

mongoose.connection.dropCollection('humen',function(err,result){
    if(err)
        console.log(err);
});



human.save();

