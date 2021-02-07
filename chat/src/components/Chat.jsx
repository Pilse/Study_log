import React, { useEffect, useState } from 'react';
import { useParams } from 'react-router-dom';
import Message from './messages';
import io from 'socket.io-client';
import ScrollToBottom from 'react-scroll-to-bottom';
import { BsFillChatFill } from "react-icons/bs";

let socket = '';
let ENDPOINT = 'localhost:5000';
let nickName = '';
function Chat() {
    if(!nickName)
    {
        nickName = prompt('이 방에서 사용하실 이름을 입력해주세요.');
        if(nickName.trim()===''){
            const randomNumber = Math.floor(Math.random()*10000+1);
            nickName=`이름없음 ${randomNumber}`;
        }
    }
    let { name } = useParams();
    const time = new Date().toLocaleTimeString('en-US', { hour: '2-digit', minute: '2-digit' });
    const [inputMsg, setInputMsg] = useState('');
    const [outputMessage, setOutputMessage] = useState([]);

    function handleChange(event) {
        event.preventDefault();
        setInputMsg(event.target.value);
    }

    async function addMsg() {
        console.log('addmsg');
        const msgTime = new Date().toLocaleTimeString('en-US', { hour: '2-digit', minute: '2-digit' });
        if (inputMsg === '')
            return;
        await socket.emit('message', {inputMsg,name,msgTime,nickName},()=>setInputMsg(''));
    }

    function handleKeypress(event) {
        if(event.key==='Enter'){
            console.log('enter');
            addMsg();
        }
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
        socket.emit('join', { name, time, user: 1 ,nickName});

        return () =>{
            socket.emit('disconnect');
            socket.off();
        } 

    }, []);

    useEffect(()=>{
        socket.on('message', (message) => {
            console.log('client: msg comes in');
            setOutputMessage(prevMsg=>[...prevMsg,message]);
        });
    },[]);
    console.log(outputMessage);

    

    return (
        <div id='chat'>
            <div className='chatContainer'>
                <div className='chatHeader'>
                    <div className='chatRoomName'><BsFillChatFill />&nbsp;&nbsp;{name}</div>
                    <a href='/'>
                        <button>Leave</button>
                    </a>

                </div>
                <ScrollToBottom className='chat'>
                    {outputMessage.map((msg,index) =>
                        <Message
                            key={index}
                            msg={msg.message}
                            who={msg.who}
                            time={msg.time}
                            username={msg.userName}
                        />)}
                </ScrollToBottom>
            </div>
            <div className="SendMsg">
                <input 
                    onChange={handleChange}  
                    onKeyPress={handleKeypress} 
                    type="text" placeholder='Enter messages' value={inputMsg}  />
                <button 
                onClick={addMsg}
                >Send</button>
            </div>
        </div>
    );
}

export default Chat;