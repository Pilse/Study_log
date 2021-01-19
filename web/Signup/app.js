const express = require('express');
const https = require('https');
const bodyParser = require('body-parser');
const request = require('request');
var app = express();
app.use(bodyParser.urlencoded({extended:true}));
app.use(express.static('public'));


app.get('/',function(req,res){

    res.sendFile(__dirname+'/signup.html');
});

app.post('/', function (req, res) {
    const firstName = req.body.firstName;
    const lastName = req.body.lastName;
    const email = req.body.email;


    const data = {
        members: [
            {
                email_address: email,
                status: 'subscribed',
                merge_fields: {
                    FNAME: firstName,
                    LNAME: lastName
                }
            }
        ]
    };

    const jsonData = JSON.stringify(data);
    const url = 'https://us7.api.mailchimp.com/3.0/lists/4f1931c081';
    const options ={
        method: 'POST',
        auth:'pilse:d194f5a113ae32622c29d0cc7d6277fd-us7'
    }

    const request = https.request(url, options, function (response) {
        response.on('data',function(data){
            console.log(JSON.parse(data));
        })
        if(response.statusCode===200)
        res.sendFile(__dirname+'/success.html');
        else
        res.sendFile(__dirname+'/failure.html');
    });

    request.write(jsonData);
    request.end();
})

app.post('/failure',function(req,res){
    res.redirect('/');
})


app.listen(process.env.PORT || 3000,function(){
    console.log('Server is running on port 3000');
})

    