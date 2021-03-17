import React from 'react';
import './NavigationItems.css';
import NavigationItem from '../NavigationItems/NavigationItem/NavigationItem';

function navigationItems() {
    return(
        <ul className="NavigationItems">
           <NavigationItem link="/" active>
               Burger Builder
           </NavigationItem>
           <NavigationItem link="/">
               CheckOut
           </NavigationItem>
        </ul>
    )
}

export default navigationItems;