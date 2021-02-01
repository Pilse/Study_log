const express = require('express');
const app=express();
const cors = require ('cors');
const api=require('./routes/index');

app.use(cors());
app.use('/api',api);

const port=3002;

app.listen(port,()=>{
    console.log('Server has started on port 3002');
})