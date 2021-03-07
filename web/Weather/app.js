const express = require('express');
const bodyParser = require('body-parser');
const https = require('https');
const { Http2ServerResponse } = require('http2');
const app = express();
app.use(bodyParser.urlencoded({extended:true}));
app.use(express.static('public'));

app.get('/',function(req,res){

    res.sendFile(__dirname+'/index.html');
});

app.post('/',function(req,res){

    var city = req.body.cityName;
    var city1 = city.toUpperCase();
    var city2 = city.toLowerCase();
    city=city1[0]+city2.slice(1,city2.length); 
    var appKey ='d8c674f08c34f10e6361d0475926a0ae';
    const url = `https://api.openweathermap.org/data/2.5/weather?q=${city}&appid=${appKey}&units=metric`;
    https.get((url),function(response){

        response.on('data',function(data){
            var weatherData = JSON.parse(data);
            var temperature = weatherData.main.temp.toFixed(1);
            var weatherDiscription = weatherData.weather[0].description;
            var icon = `http://openweathermap.org/img/wn/${weatherData.weather[0].icon}@2x.png`
    
            res.write(`<!DOCTYPE html>
            <html lang="en">
            
            <head>
                <meta charset="UTF-8">
                <meta name="viewport" content="width=device-width, initial-scale=1.0">
                
                <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-giJF6kkoqNQ00vy+HMDP7azOuL0xtbfIcaT9wjKHr8RbDVddVHyTfAAsrekwKmP1" crossorigin="anonymous">
                <link rel="stylesheet" href="css/styles.css">
                <link rel="preconnect" href="https://fonts.gstatic.com">
              <link
                href="https://fonts.googleapis.com/css2?family=Montserrat:wght@400;500;900&family=Ubuntu:ital,wght@0,300;0,400;0,500;1,300&display=swap"
                rel="stylesheet">
            
                <title>Weather App</title>
            </head>
            
            <body>
                <div class="container">
                    <form action="/" method="POST">
                        <label class="label" for="cityName">How's the <span>weather</span> in &nbsp;</label>
                        <input class='type' type="text" id="cityName" placeholder="&nbsp;City Name" name='cityName'>
                        <button class="button" type="submit">Go</button>
                    </form>
                </div>
            </body>
            
            </html>`)
            res.write(`<h1><span>${city}</span> is now <span>${temperature} 'C</span> </h1>`);
            res.write(`<h3>${weatherDiscription} </h3>`);
            res.write(`<img src='${icon}'>`);
            res.send();

        }); 
    });

});
   


app.listen(3000,function(){

});
