const express = require('express');
const cors = require ('cors');
const socket = require ('socket.io');
const route = require('./routes/index');
const http = require('http');


const app = express();
const server = http.createServer(app);
const io = socket(server);

app.use(cors());
app.use('/',route);

const rooms = [];

async function addRoom (id,room,time,user) {
    const newRoom = {id:id,room:room,time:time,user:user};
    await rooms.push(newRoom);
    return rooms;
}

function deleteRoom(id) {
    const index= rooms.findIndex(foundRoom=>foundRoom.id===id);
    return rooms.splice(index, 1)[0];
}

function addUser (room){
    const index= rooms.findIndex(foundRoom=>foundRoom.room===room);
    rooms[index].user = rooms[index].user+1;
    return rooms;
}


io.on('connect',(socket)=>{
    socket.emit('rooms',rooms);
    socket.on('rooms',async (room)=>
    {
        const t = await rooms.find(foundroom=>(foundroom.room===room.room));
        if(t){
            addUser(room.room);
            socket.broadcast.emit('rooms',rooms);
        }
        else{
            addRoom(socket.id,room.room,room.time,room.user);
            socket.broadcast.emit('rooms',rooms);
        }
    });
    socket.on('join',(room)=>{
        console.log(room.name);
        socket.join(room.name);
    })

    socket.on('disconnect',()=>{
        console.log('disconect');
    })
})

const port=5000;

server.listen(port,()=>{
    console.log(`Server has started on port ${port}`);
})