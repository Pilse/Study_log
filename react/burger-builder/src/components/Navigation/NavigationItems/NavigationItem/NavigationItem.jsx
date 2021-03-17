import React from 'react';
import './NavigationItem.css';


function navigationItem(props) {
    return(
        <li className="NavigationItem">
            <a href={props.link} className={props.active ? 'active' : null}>{props.children}</a>
        </li>
    )
}

export default navigationItem;