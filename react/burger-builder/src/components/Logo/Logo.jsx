import React from 'react';
import burgerLogo from '../../assets/image/burger-logo.png';
import './Logo.css';


function logo(props) {
    return(
        <div className="Logo" style ={{height:props.height}}>
            <img src={burgerLogo} alt="myBurger"/>
        </div>
    );
}

export default logo;