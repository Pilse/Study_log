const express = require('express');
const bodyParser = require('body-parser');
var app = express();
app.use(bodyParser.urlencoded({extended:true}));

app.get('/',function(req,res){
    res.sendFile(__dirname+'/index.html');
});
app.post('/',function(req,res){
    var height = req.body.num1;
    var weigth = req.body.num2;
    var BMI = (weigth/(height^2)).toFixed(2);
    res.send('Your BMI is '+BMI);
});

app.listen(3000);