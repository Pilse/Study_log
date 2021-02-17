import React, { useEffect, useMemo, useState } from "react";
import Header from "./Header";
import Footer from "./Footer";
import Note from "./Note";
import CreateArea from "./CreateArea";

function App() {

    const [allNotes, setAllNotes] = useState({
        title: [],
        body: []
    });

    function addItem(noteContent) {
        setAllNotes(prevValue => {
            return {
                title: [...prevValue.title, noteContent.title],
                body: [...prevValue.body, noteContent.body]
            }
          
        });
    }

    function deleteItem(id) {
        setAllNotes((prevItems) => {
            return{
                title: prevItems.title.filter((title,index)=>{return index!==id}),
                body: prevItems.body.filter((body,index)=>{return index!==id})
            }
        });
    }
    useEffect(()=>{
        console.log('effect start');
        return(()=>{
            console.log('effect finish');
        })
    },[allNotes])
    console.log('render');

    return (
        <div>
            <Header />
            <CreateArea addItem={addItem} />
            {allNotes.title.map((title, index) => {
                return <Note
                    key={index}
                    id={index}
                    title={title}
                    body={allNotes.body[index]}
                    deleteItem={deleteItem}
                />
            })}

            <Footer />
        </div>
    );
}

export default App;
