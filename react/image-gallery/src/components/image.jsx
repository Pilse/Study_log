import React from 'react';
import Tags from './Tags';

function Image({img, user, views, downloads, likes, tags}) {
    const imgTags=tags.split(',');
    console.log(imgTags);
    return (
        <div className="container">
            <img src={img} alt="" />
            <div className="photo-info">
                <div><strong>Photo by</strong> <span className="author">{user}</span></div>
            </div>
            <ul>
                <li>
                    <strong>Views: </strong>{views}
                </li>
                <li>
                    <strong>Downloads: </strong>{downloads}
                </li>
                <li>
                    <strong>Likes: </strong>{likes}
                </li>
            </ul>
            <div className="tags">
           {imgTags.map((tag,idx)=>
           <Tags 
               key={idx}
               tag={tag}
           />)}
           </div>
        </div>
    )
}

export default Image;