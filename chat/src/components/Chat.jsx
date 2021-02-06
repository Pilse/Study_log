import React, { useEffect, useRef, useState } from 'react';
import { useParams } from 'react-router-dom';
import Message from './messages';
import io from 'socket.io-client';
import ScrollToBottom from 'react-scroll-to-bottom';
import messages from './messages';

let socket = '';
let ENDPOINT = 'localhost:5000';

function Chat() {
    let { name } = useParams();
    const time = new Date().toLocaleTimeString('en-US', { hour: '2-digit', minute: '2-digit' });
    const [inputMsg, setInputMsg] = useState('');
    const [outputMessage, setOutputMessage] = useState([]);

    function handleChange(event) {
        event.preventDefault();
        setInputMsg(event.target.value);
    }

    function addMsg(event) {
        console.log('addmsg');
        if (inputMsg === '')
            return;
        socket.emit('message', {inputMsg,name},()=>setInputMsg(''));

    }

    useEffect(() => {
        var connectionOptions = {
            "force new connection": true,
            "reconnectionAttempts": "Infinity",
            "timeout": 10000,
            "transports": ["websocket"]
        };
        console.log('enter room');
        socket = io(ENDPOINT, connectionOptions);
        socket.emit('join', { name, time, user: 1 });

        return () =>{
            socket.emit('disconnect');
            socket.off();
        } 

    }, [ENDPOINT]);

    useEffect(() => {

        console.log('useeffect messages');
        socket.on('message', (message) => {
            setOutputMessage([...outputMessage,message]);
        });
    },[outputMessage]);
    console.log('render');
   

    return (
        <div id='chat'>
            <div className='chatContainer'>
                <div className='chatHeader'>
                    <div className='chatRoomName'>{name}</div>
                    <a href='/'>
                        <button>Leave</button>
                    </a>

                </div>
                <div className='chat'>
                    {outputMessage.map(msg =>
                        <Message
                            msg={msg.message}
                            who={msg.who}
                        />)}
                </div>
            </div>
            <div className="SendMsg">
                <input onChange={handleChange}  onKeyDown={(event)=>event.key==='Enter' ? addMsg():null} type="text" placeholder='Enter messages' value={inputMsg}  />
                <button 
                onClick={addMsg}
                >Send</button>
            </div>
        </div>
    );
}

export default Chat;