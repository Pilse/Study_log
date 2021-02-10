import React, { useState } from 'react';
import { Link } from 'react-router-dom';
import Room from './Room'




const ENDPOINT = 'http://localhost:5000';

function Rooms() {

    const [inputRoom, setInputRoom] = useState('');
    const [Rooms, setRooms] = useState([]);

    function handleChange(event) {
        setInputRoom(event.target.value);
    }
    

    useState(() => {
        const fetchDatas = async () => {
            const res = await fetch(`${ENDPOINT}/rooms`);
            const rooms = await res.json();
            setRooms(rooms);
        }
        fetchDatas();
    },[Rooms]);



    return (
        <div>
            <div className='roomCreate'>
                <input 
                    onChange={handleChange}
                    type="text" placeholder="Create New Room" value={inputRoom} />
                <Link onClick={(event)=>(!inputRoom||Rooms.find(room=>room.room===inputRoom)) ? (event.preventDefault(),alert('이미 존재하는 방 이름입니다.')):null} to={`/chat/${inputRoom}`} >
                    <button>+</button>
                </Link>
            </div>
            <h1 className='index'>Rooms</h1>
            <div className='allRooms'>
                {Rooms.map((room) => <Room key={room.id} room={room.room} time={room.time} user={room.user} color={room.color}/>)}
            </div>
        </div>
    );
}

export default Rooms;