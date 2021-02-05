import React from 'react';
import {Link} from 'react-router-dom';

function Room({room, time, user}) {
    return (
        <Link to={`/chat/${room}`}>
            <div className='roomContainer'>
                <div className='roomTop'>{room}</div>
                <div className='roomBot'>
                    <p>{time}</p>
                    <p>USER : {user}</p>
                </div>
            </div>
        </Link>
    );
}

export default Room;