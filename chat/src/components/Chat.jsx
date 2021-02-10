import React, { useEffect, useRef, useState } from 'react';
import { useParams } from 'react-router-dom';
import io from 'socket.io-client';
import ScrollToBottom from 'react-scroll-to-bottom';
import { BsFillChatFill } from "react-icons/bs";
import Messages from './Messages';

let socket = '';
let ENDPOINT = 'localhost:5000';
let nickName = '';

function Chat() {
    if (!nickName) {
        nickName = prompt('이 방에서 사용하실 이름을 입력해주세요.');
        if (nickName.trim() === '') {
            const randomNumber = Math.floor(Math.random() * 10000 + 1);
            nickName = `이름없음 ${randomNumber}`;
        }
    }
    let { name } = useParams();
    const time = new Date().toLocaleTimeString('en-US', { hour: '2-digit', minute: '2-digit' });
    const [inputMsg, setInputMsg] = useState('');
    const [outputMessage, setOutputMessage] = useState([]);
    const [translateState, setTranslateState] = useState(false);
    const [source, setSource] = useState('');
    const [target, setTarget] = useState('');
    const [userNum, setUserNum] = useState('');
    const Fromfocus = useRef();

    let translateStyle = {
        backgroundColor: 'white',
        color: 'red'
    }
    
    if (!translateState)
        translateStyle.color = '#00adb5';


    function handleChange(event) {
        event.preventDefault();
        setInputMsg(event.target.value);
    }

    async function changeTranslatState(event) {
        await setTranslateState(!translateState);
        if (translateState === false) {
            setSource('');
            setTarget('');
        }
        Fromfocus.current.scrollIntoView({behavior:'smooth',block:'end'});
    }

    async function addMsg() {
        console.log('addmsg');
        const msgTime = new Date().toLocaleTimeString('en-US', { hour: '2-digit', minute: '2-digit' });
        if (inputMsg === '')
            return;
        await socket.emit('message', { translateState, source, target, inputMsg, name, msgTime, nickName }, () => setInputMsg(''));
    }

    function handleKeypress(event) {
        if (event.key === 'Enter') {
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
        socket.emit('join', { name, time, user: 1, nickName });

        return () => {
            socket.emit('disconnect');
            socket.off();
        }

    }, []);

    useEffect(() => {
        socket.on('message', (message) => {
            console.log('client: msg comes in');
            setOutputMessage(prevMsg => [...prevMsg, message]);
            setUserNum(message.usernum);
        });
    }, []);
   


    return (
        <div ref={Fromfocus} id='chat'>
            <div className='chatContainer'>
                <div className='chatHeader'>
                    <div className='chatRoomName'><BsFillChatFill />&nbsp;&nbsp;{name}({userNum})</div>
                    <a href='/'>
                        <button>Leave</button>
                    </a>

                </div>
                <ScrollToBottom className='chat'>
                    {outputMessage.map((msg, index) =>
                        <Messages
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
                    type="text" placeholder='Enter messages' value={inputMsg} />
                <button onClick={addMsg}>Send</button>
                <button style={translateStyle} className='translate' onClick={changeTranslatState}>{translateState ? '번역끄기' : '번역켜기'}</button>
            </div>
            <div className='translateOption'>
                {translateState ?
                    <div className='translateFrom'>
                        <h1 className='tranIndex'>From<span className='indexSpan'>&nbsp;{source}</span></h1>
                        <button onClick={() => {setSource('ko'); setTarget('')}}>KO</button>
                        <button onClick={() => {setSource('en'); setTarget('')}}>EN</button>
                        <button onClick={() => {setSource('ja'); setTarget('')}}>JA</button>
                        <button onClick={() => {setSource('zh-CN'); setTarget('')}}>zh-CN</button>
                        <button onClick={() => {setSource('zh-TW'); setTarget('')}}>zh-TW</button>
                        <button onClick={() => {setSource('vi'); setTarget('')}}>VI</button>
                        <button onClick={() => {setSource('id'); setTarget('')}}>ID</button>
                        <button onClick={() => {setSource('th'); setTarget('')}}>TH</button>
                        <button onClick={() => {setSource('de'); setTarget('')}}>DE</button>
                        <button onClick={() => {setSource('ru'); setTarget('')}}>RU</button>
                        <button onClick={() => {setSource('es'); setTarget('')}}>ES</button>
                        <button onClick={() => {setSource('it'); setTarget('')}}>IT</button>
                        <button onClick={() => {setSource('fr'); setTarget('')}}>FR</button>
                    </div>
                    : null
                }
                {translateState && source ?
                    <div className='translateTo'>
                        <h1 className='tranIndex'>To<span className='indexSpan'>&nbsp;{target}</span></h1>
                        {source === 'ko' ?
                            <div>
                                <button onClick={() => setTarget('en')}>EN</button>
                                <button onClick={() => setTarget('ja')}>JA</button>
                                <button onClick={() => setTarget('zh-CN')}>zh-CN</button>
                                <button onClick={() => setTarget('zh-TW')}>zh-TW</button>
                                <button onClick={() => setTarget('vi')}>VI</button>
                                <button onClick={() => setTarget('id')}>ID</button>
                                <button onClick={() => setTarget('th')}>TH</button>
                                <button onClick={() => setTarget('de')}>DE</button>
                                <button onClick={() => setTarget('ru')}>RU</button>
                                <button onClick={() => setTarget('es')}>ES</button>
                                <button onClick={() => setTarget('it')}>IT</button>
                                <button onClick={() => setTarget('fr')}>FR</button>
                            </div> : null}
                        {source === 'en' ?
                            <div>
                                <button onClick={() => setTarget('ko')}>KO</button>
                                <button onClick={() => setTarget('ja')}>JA</button>
                                <button onClick={() => setTarget('zh-CN')}>zh-CN</button>
                                <button onClick={() => setTarget('zh-TW')}>zh-TW</button>
                                <button onClick={() => setTarget('fr')}>FR</button>
                            </div> : null}
                        {source === 'ja' ?
                            <div>
                                <button onClick={() => setTarget('ko')}>KO</button>
                                <button onClick={() => setTarget('en')}>EN</button>
                                <button onClick={() => setTarget('zh-CN')}>zh-CN</button>
                                <button onClick={() => setTarget('zh-TW')}>zh-TW</button>
                            </div> : null}
                        {source === 'zh-CN' ?
                            <div>
                                <button onClick={() => setTarget('ko')}>KO</button>
                                <button onClick={() => setTarget('en')}>EN</button>
                                <button onClick={() => setTarget('ja')}>JA</button>
                                <button onClick={() => setTarget('zh-TW')}>zh-TW</button>
                            </div> : null}
                        {source === 'zh-TW' ?
                            <div>
                                <button onClick={() => setTarget('ko')}>KO</button>
                                <button onClick={() => setTarget('en')}>EN</button>
                                <button onClick={() => setTarget('ja')}>JA</button>
                                <button onClick={() => setTarget('zh-CN')}>zh-CN</button>
                            </div> : null}
                        {source === 'vi' ?
                            <div>
                                <button onClick={() => setTarget('ko')}>KO</button>
                            </div> : null}
                        {source === 'id' ?
                            <div>
                                <button onClick={() => setTarget('ko')}>KO</button>
                            </div> : null}
                        {source === 'th' ?
                            <div>
                                <button onClick={() => setTarget('ko')}>KO</button>
                            </div> : null}
                        {source === 'de' ?
                            <div>
                                <button onClick={() => setTarget('ko')}>KO</button>
                            </div> : null}
                        {source === 'ru' ?
                            <div>
                                <button onClick={() => setTarget('ko')}>KO</button>
                            </div> : null}
                        {source === 'es' ?
                            <div>
                                <button onClick={() => setTarget('ko')}>KO</button>
                            </div> : null}
                        {source === 'it' ?
                            <div>
                                <button onClick={() => setTarget('ko')}>KO</button>
                            </div> : null}
                        {source === 'fr' ?
                            <div>
                                <button onClick={() => setTarget('ko')}>KO</button>
                                <button onClick={() => setTarget('en')}>EN</button>
                            </div> : null}
                    </div> : null}
            </div>
        </div>
    );
}

export default Chat;