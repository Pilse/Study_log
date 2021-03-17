import React from 'react';
import './Button.css';

function button(props) {
    return (<button 
        onClick={props.clicked}
        className={["Button", props.btnType].join(' ')}>
            {props.children}
    </button>
    );
}

export default button;