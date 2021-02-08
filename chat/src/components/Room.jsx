import React from 'react';
import {Link} from 'react-router-dom';
import {BsFillPersonFill} from 'react-icons/bs';
import { MdQueryBuilder } from "react-icons/md";


function Room({room, time, user}) {
    const randomNumber =Math.floor(Math.random()*3+1);
    let color = '';
    switch (randomNumber){
        case 1:
            color='#f4f9f9';
            break;
        case 2:
            color='#eeeeee';
            break;
        case 3:
            color='#AAAAAA';
            break;
        default:
            color='#eeeeee';
            break;
    }


    return (
        <Link to={`/chat/${room}/`}>
            <div className='roomContainer'>
                <div className='roomTop' style={{backgroundColor:color}}>&nbsp;{room}</div>
                <div className='roomBot'>
                    <p>&nbsp;<MdQueryBuilder /> &nbsp;{time}</p>
                    <p>&nbsp;<BsFillPersonFill /> &nbsp;{user}</p>
                </div>
            </div>
        </Link>
    );
}

export default Room;