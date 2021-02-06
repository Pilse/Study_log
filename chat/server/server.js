const express = require('express');
const cors = require ('cors');
const socket = require ('socket.io');
const http = require('http');


const app = express();
const server = http.createServer(app);
const io = socket(server);

app.use(cors());
app.get('/',(req,res)=>{
    res.send('server is running');
})

const rooms = [];

app.get('/rooms',(req,res)=>{
    res.send(JSON.stringify(rooms));
})



async function addRoom (id,name,time,user,userid) {
    const newRoom = {id:id,room:name,time:time,user:user,userIds:[userid]};
    await rooms.push(newRoom);
    return rooms;
}

function deleteRoom(room) {
    const index= rooms.findIndex(foundRoom=>foundRoom.room===room);
    return rooms.splice(index, 1)[0];
}


io.on('connection',(socket)=>{
  console.log('new user joined');

  socket.on('join',({name, time, user})=>{
      const foundRoom=rooms.findIndex(room=>room.room===name);
      if(foundRoom>=0){
        rooms[foundRoom].user=rooms[foundRoom].user+1;
        rooms[foundRoom].userIds.push(socket.id);
        socket.join(name);
      }
      else{
        addRoom(socket.id,name,time,user,socket.id);
        socket.join(name);
      }
    socket.on('message',(props,callback)=>{
        socket.broadcast.to(props.name).emit('message',{message:props.inputMsg,who:'other'});
        socket.emit('message',{message:props.inputMsg,who:'me'});
        callback();
    })
  })
    
  socket.on('disconnect',()=>{
        console.log('user disconnected');
        const disconnectedRoom = rooms.findIndex(room=>
        room.userIds.find(userId=>
            socket.id===userId
            )
        )
        const disconnectedUserId=rooms[disconnectedRoom].userIds.findIndex(userId=>userId===socket.id);
        if(rooms[disconnectedRoom].user===1)
            deleteRoom(rooms[disconnectedRoom].room);
        else{
            rooms[disconnectedRoom].user=rooms[disconnectedRoom].user-1;
            rooms[disconnectedRoom].userIds.splice(disconnectedUserId,1);
        }

  })
})

const port=5000;

server.listen(port,()=>{
    console.log(`Server has started on port ${port}`);
})