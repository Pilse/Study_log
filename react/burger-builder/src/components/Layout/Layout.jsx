import React from 'react';
import './Layout.css'
import Toolbar from '../Navigation/Toolbar/Toolbar';

function layout ({ children }){
    return(
        <>
            <Toolbar />
            <main className="Content">{children}</main>
        </>
    )
}

export default layout;