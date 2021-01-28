import React from "react";

const Avatar = function(props){
    return (
        <img className='circle-img'
            src={props.imgURL}
            alt="avatar_img"
          />
    );
}

export default Avatar