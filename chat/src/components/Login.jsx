import React from 'react';

function Login () {


    return( 
    <div className='loginContainer'>
        <div className='loginLeftContainer'>
            <h1>Login</h1>
            <form action="">
                <label>Name</label>
                <input type="text" name="userName" placeholder="Enter Name"/>
                <label>Password</label>
                <input type="password" name="userPassword" placeholder="Enter Password"/>
            </form>
            <p>Sign Up</p>
        </div>
    </div>
    );
}

export default Login;