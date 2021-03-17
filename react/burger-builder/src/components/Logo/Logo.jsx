import React from 'react';
import burgerLogo from '../../assets/image/burger-logo.png';
import './Logo.css';


function logo(props) {
    return(
        <div className="Logo">
            <img src={burgerLogo} alt="myBurger"/>
        </div>
    );
}

export default logo;