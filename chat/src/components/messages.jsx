import React from 'react';

function messages({ msg, who, time, username}) {
    return (
        <>
            {who === 'me' &&
                <div className='rightMsg'>
                    <div className='RowMsg'>
                        <div className='info'>{time}</div>
                        <p>{msg}</p>
                    </div>
                </div>}
            {who === 'other' &&
                <div className='leftMsg'>
                    <div className='info infoname'>{username}</div>
                    <div className='RowMsg'>
                        <p>{msg}</p> <div className='info'>{time}
                        </div></div>
                     </div>
            }
            {who === 'bot' &&
                <div className='botMsg'>
                    <p>{msg}</p>
                </div>
            }

        </>
    );
}

export default messages;