import React, { useEffect } from 'react';
import {Link, useParams} from 'react-router-dom';
import Message from './messages';
import io from 'socket.io-client';

let socket='';
let ENDPOINT ='localhost:5000';

function Chat() {
    let { name } = useParams();
    const time = new Date().toLocaleTimeString();

    useEffect(() => {
        var connectionOptions = {
            "force new connection": true,
            "reconnectionAttempts": "Infinity",
            "timeout": 10000,
            "transports": ["websocket"]
        };

        socket = io(ENDPOINT, connectionOptions);

        socket.emit('rooms',{room:name, time:time, user:1});
        socket.emit('join',{name});

    },[name,time]);

    return (
        <div id='chat'>
            <div className='chatContainer'>
                <div className='chatHeader'>
                    <div>{name}</div>
                    <Link to='/'><button>Leave</button>
                    </Link>
                    
                </div>
                <div className='chat'>
                    <Message />
                </div>
            </div>
            <div className="SendMsg">
                <input type="text" placeholder='Enter messages' />
                <button> Send</button>
            </div>
        </div>
    );
}

export default Chat;