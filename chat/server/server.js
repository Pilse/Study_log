const express = require('express');
const cors = require('cors');
const socket = require('socket.io');
const http = require('http');
const request = require('request');

const clientId = 'RurOk_Ria5XOSbOTUHgJ';
const clientSecret = 'tJrjzyknPV';

const app = express();
const server = http.createServer(app);
const io = socket(server);

app.use(cors());
app.get('/', (req, res) => {
    res.send('server is running');
})

const rooms = [];

app.get('/rooms', (req, res) => {
    res.send(JSON.stringify(rooms));
})



async function addRoom(id, name, time, user, nickName) {
    const newRoom = { id: id, room: name, time: time, user: user, userIds: [{ sid: id, nickName }], color:Math.floor(Math.random()*3+1)};
    await rooms.push(newRoom);
    return rooms;
}

function deleteRoom(room) {
    const index = rooms.findIndex(foundRoom => foundRoom.room === room);
    return rooms.splice(index, 1)[0];
}



io.on('connection', (socket) => {
    console.log('new user joined');

    socket.on('join', (props) => {
        const foundRoom = rooms.findIndex(room => room.room === props.name);
        if (foundRoom >= 0) {
            rooms[foundRoom].user = rooms[foundRoom].user + 1;
            const userNumber = rooms[foundRoom].user;
            rooms[foundRoom].userIds.push({ sid: socket.id, nickName: props.nickName });
            socket.join(props.name);
            io.to(props.name).emit('message', { message: `${props.nickName}님이 입장하셨습니다.`, who: 'bot', usernum:userNumber});
        }
        else {
            addRoom(socket.id, props.name, props.time, props.user, props.nickName);
            socket.join(props.name);
            io.to(props.name).emit('message', { message: `${props.nickName}님이 입장하셨습니다.`, who: 'bot',usernum:1 });
        }
    })
    socket.on('message', (props, callback) => {
        const roomNumber = rooms.findIndex(room=>room.room===props.name);
        const userNumber = rooms[roomNumber].user;
        if(props.source===''||props.target==='')
            props.translateState=false;
        if (props.translateState) {
            console.log(props.source);
            console.log(props.target);
            const translateOptions = {
                url: 'https://openapi.naver.com/v1/papago/n2mt',
                form: { 'source': props.source, 'target': props.target, 'text': props.inputMsg },
                headers: { 'X-Naver-Client-Id': clientId, 'X-Naver-Client-Secret': clientSecret }
            }
            request.post(translateOptions, (err, res, body) => {
                props.inputMsg = JSON.parse(body).message.result.translatedText;
                socket.broadcast.to(props.name).emit('message', { message: props.inputMsg, who: 'other', time: props.msgTime, userName: props.nickName, usernum:userNumber });
                socket.emit('message', { message: props.inputMsg, who: 'me', time: props.msgTime, usernum:userNumber });
                callback();
            })

        } else {
            socket.broadcast.to(props.name).emit('message', { message: props.inputMsg, who: 'other', time: props.msgTime, userName: props.nickName, usernum:userNumber });
            socket.emit('message', { message: props.inputMsg, who: 'me', time: props.msgTime, usernum:userNumber });
            callback();
        }
    })


    socket.on('disconnect', () => {
        console.log('user disconnected');
        const disconnectedRoom = rooms.findIndex(room =>
            room.userIds.find(userId =>
                socket.id === userId.sid
            )
        )
        const disconnectedUserId = rooms[disconnectedRoom].userIds.findIndex(userId => userId.sid === socket.id);
        io.to(rooms[disconnectedRoom].room).emit('message', { message: `${rooms[disconnectedRoom].userIds[disconnectedUserId].nickName}님이 퇴장하셨습니다.`, who: 'bot', usernum:rooms[disconnectedRoom].user-1})
        if (rooms[disconnectedRoom].user === 1)
            deleteRoom(rooms[disconnectedRoom].room);
        else {
            rooms[disconnectedRoom].user = rooms[disconnectedRoom].user - 1;
            rooms[disconnectedRoom].userIds.splice(disconnectedUserId, 1);
        }


    })
})


const port = 5000;

server.listen(port, () => {
    console.log(`Server has started on port ${port}`);
})