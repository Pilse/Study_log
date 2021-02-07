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



async function addRoom (id,name,time,user,nickName) {
    const newRoom = {id:id,room:name,time:time,user:user,userIds:[{sid:id,nickName}]};
    await rooms.push(newRoom);
    return rooms;
}

function deleteRoom(room) {
    const index= rooms.findIndex(foundRoom=>foundRoom.room===room);
    return rooms.splice(index, 1)[0];
}


io.on('connection',(socket)=>{
  console.log('new user joined');

  socket.on('join',({name, time, user, nickName})=>{
      const foundRoom=rooms.findIndex(room=>room.room===name);
      if(foundRoom>=0){
        rooms[foundRoom].user=rooms[foundRoom].user+1;
        rooms[foundRoom].userIds.push({sid:socket.id,nickName:nickName});
        socket.join(name);
        io.to(name).emit('message',{message:`${nickName}님이 입장하셨습니다.`,who:'bot'});
      }
      else{
        addRoom(socket.id,name,time,user,nickName);
        socket.join(name);
        io.to(name).emit('message',{message:`${nickName}님이 입장하셨습니다.`,who:'bot'});
      }
    socket.on('message',(props,callback)=>{
        console.log('server: msg comes in');
        socket.broadcast.to(props.name).emit('message',{message:props.inputMsg,who:'other',time:props.msgTime,userName:props.nickName});
        socket.emit('message',{message:props.inputMsg,who:'me',time:props.msgTime});
        callback();
    })
  })
    
  socket.on('disconnect',()=>{
        console.log('user disconnected');
        const disconnectedRoom = rooms.findIndex(room=>
        room.userIds.find(userId=>
            socket.id===userId.sid
            )
        )
        const disconnectedUserId=rooms[disconnectedRoom].userIds.findIndex(userId=>userId.sid===socket.id);
        io.to(rooms[disconnectedRoom].room).emit('message',{message:`${rooms[disconnectedRoom].userIds[disconnectedUserId].nickName}님이 퇴장하셨습니다.`,who:'bot'})
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