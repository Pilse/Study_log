import React from 'react';
import {Link} from 'react-router-dom';
import {BsFillPersonFill} from 'react-icons/bs';
import { MdQueryBuilder } from "react-icons/md";


function Room({room, time, user, color}) {
    
    let Roomcolor = '';
    switch (color){
        case 1:
            Roomcolor='#f4f9f9';
            break;
        case 2:
            Roomcolor='#eeeeee';
            break;
        case 3:
            Roomcolor='#AAAAAA';
            break;
        default:
            Roomcolor='#eeeeee';
            break;
    }


    return (
        <Link to={`/chat/${room}/`}>
            <div className='roomContainer'>
                <div className='roomTop' style={{backgroundColor:Roomcolor}}>&nbsp;{room}</div>
                <div className='roomBot'>
                    <p>&nbsp;<MdQueryBuilder /> &nbsp;{time}</p>
                    <p>&nbsp;<BsFillPersonFill /> &nbsp;{user}</p>
                </div>
            </div>
        </Link>
    );
}

export default Room;