const express = require('express');
const bodyParser = require('body-parser');
const https = require('https');
const app = express();
app.use(bodyParser.urlencoded({extended:true}));

app.get('/',function(req,res){

    res.sendFile(__dirname+'/index.html');
});

app.post('/',function(req,res){

    var city = req.body.cityName;
    var appKey ='d8c674f08c34f10e6361d0475926a0ae';
    const url = `https://api.openweathermap.org/data/2.5/weather?q=${city}&appid=${appKey}&units=metric`;

    https.get((url),function(response){

        response.on('data',function(data){
            var weatherData = JSON.parse(data);
            var temperature = weatherData.main.temp;
            var weatherDiscription = weatherData.weather[0].description;
            var icon = `http://openweathermap.org/img/wn/${weatherData.weather[0].icon}@2x.png`
    
            res.write(`<!DOCTYPE html>
            <html lang="en">
            <head>
                <meta charset="UTF-8">
                <meta name="viewport" content="width=device-width, initial-scale=1.0">
                <title>Weather App</title>
            </head>
            <body>
                <form action="/" method="post">
                    <label for="cityName">City &nbsp;</label>
                    <input type="text" id="cityName" placeholder="City Name" name='cityName'>
                    <button type="submit">Go</button>
                </form>
            </body>
            </html>`);
            res.write(`<h1>${city} is now ${temperature} 'C </h1>`);
            res.write(`<h3>${weatherDiscription} </h3>`);
            res.write(`<img src='${icon}'>`);
            res.send();

        }); 
    });

});
   


app.listen(3000,function(){

});
