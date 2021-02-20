import React, { useEffect, useState } from 'react';
import Image from './image';

function App() {
    const [images, setImages] = useState([]);
    const [term, setTerm] = useState('');

    useEffect(() => {
        fetch(`https://pixabay.com/api/?key=20347122-4793d2356cda48cfa1262ceb2&q=${term}&image_type=photo&pretty=true`)
            .then(res => res.json())
            .then(data => setImages(data.hits))
            .catch(err => console.log(err));
    }, [term])

    return (
        <div className='gallery'>
            {images.map(image => <Image
                key={image.id}
                img={image.webformatURL}
                user={image.user}
                views={image.views}
                downloads={image.downloads}
                likes={image.likes}
                tags={image.tags}
            />)}
        </div>
    );
}

export default App;