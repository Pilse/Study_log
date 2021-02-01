import React, { useState } from "react";

function CreateArea(props) {
    const [noteContent, setNoteContent] = useState({
        title: '',
        body: ''
    });

    function handleChange(event) {
        const { name, value } = event.target;
        setNoteContent(prevValue => {
            return {
                ...prevValue,
                [name]: value
            }
        });
    }
    function handleClick(event){
        props.addItem(noteContent);
        setNoteContent({
            title:'',
            body:''
        })
        event.preventDefault();
    }

    return (
        <div>
            <form>
                <input onChange={handleChange} name="title" value={noteContent.title} placeholder="Title"  />
                <textarea onChange={handleChange} name="body" value={noteContent.body} placeholder="Take a note..." rows="3" />
                <button onClick={handleClick}>Add</button>
            </form>
        </div>
    );
}

export default CreateArea;
