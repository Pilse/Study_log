const express = require('express');
const router = express.Router();

router.get('/',(req,res)=>{
    res.send(JSON.stringify([{hi:'pilse'},{hi:'john'}]));
})

module.exports=router;