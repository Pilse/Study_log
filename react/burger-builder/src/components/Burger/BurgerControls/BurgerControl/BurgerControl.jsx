import React from 'react';
import './BurgerControl.css'

function burgerControl (props) {
    return(
    <div className="BuildControl">
        <div className="Label">{props.label}</div>
        <button className="Less" onClick={props.deleted} disabled={props.disabled}>Less</button>
        <button className="More" onClick={props.added}>More</button>
    </div>
    );
}

export default burgerControl