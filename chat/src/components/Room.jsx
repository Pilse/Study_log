import React from 'react';
import {Link} from 'react-router-dom';
import {BsFillPersonFill} from 'react-icons/bs';
import { MdQueryBuilder } from "react-icons/md";


function Room({room, time, user}) {
    return (
        <Link to={`/chat/${room}/`}>
            <div className='roomContainer'>
                <div className='roomTop'>&nbsp;{room}</div>
                <div className='roomBot'>
                    <p>&nbsp;<MdQueryBuilder /> &nbsp;{time}</p>
                    <p>&nbsp;<BsFillPersonFill /> &nbsp;{user}</p>
                </div>
            </div>
        </Link>
    );
}

export default Room;