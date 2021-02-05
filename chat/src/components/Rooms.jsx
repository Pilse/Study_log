import io from 'socket.io-client';
import React, { useEffect, useState } from 'react';
import { Link , useParams} from 'react-router-dom';
import Room from './Room'

let socket = '';
let ENDPOINT ='localhost:5000';

function Rooms() {
    const id = useParams();
    const [inputRoom, setInputRoom] = useState('');
    const [Rooms, setRooms] = useState([]);

    function handleChange(event) {
        setInputRoom(event.target.value);
    }    
    useEffect(() => {
        var connectionOptions = {
            "force new connection": true,
            "reconnectionAttempts": "Infinity",
            "timeout": 10000,
            "transports": ["websocket"]
        };

        socket = io(ENDPOINT, connectionOptions);
        socket.on('rooms',(rooms)=>{
            setRooms(rooms);
        })
    },[id])
    console.log(id);


    return (
        <div>
            <div className='roomCreate'>
                <input onChange={handleChange} type="text" placeholder="Create Room Name" value={inputRoom} />
                <Link  to={`/chat/${inputRoom}`} >
                    <button>+</button>
                </Link>
            </div>
            <div className='allRooms'>
                {Rooms.map((room) => <Room key={room.id} room={room.room} time={room.time} user={room.user} />)}
            </div>
        </div>
    );
}

export default Rooms;