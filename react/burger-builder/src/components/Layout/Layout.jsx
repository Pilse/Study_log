import React from 'react';
import './Layout.css'

function layout ({ children }){
    return(
        <>
            <div>Toolbar, SideDrawer, Backdrop</div>
            <main className="Content">{children}</main>
        </>
    )
}

export default layout;