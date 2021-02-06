import React from 'react';

function messages({ msg, who }) {
    return (
        <>
            {who === 'me' &&
                <div className='rightMsg'>
                    <p>{msg}</p>
                </div>}
            {who === 'other' &&
                <div className='leftMsg'>
                    <p>{msg}</p>
                </div>
            }

        </>
    );
}

export default messages;