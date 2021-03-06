import React from "react";
import Card from './Card';
import contacts from '../contacts';

function createCard(contact) {
    return (
        <Card
            key ={contact.id}
            name={contact.name}
            imgURL={contact.imgURL}
            phone={contact.phone}
            email={contact.email}
        />
    );
}


function App(props) {
    return (
        <div>
            <h1 className="heading">My Contacts</h1>
            {contacts.map(createCard)}
            {/* <Card
                name={contracts[0].name}
                imgURL={contracts[0].imgURL}
                phone={contracts[0].phone}
                email={contracts[0].email}
            />
            <Card
                name={contracts[1].name}
                imgURL={contracts[1].imgURL}
                phone={contracts[1].phone}
                email={contracts[1].email}
            />
            <Card
                name={contracts[2].name}
                imgURL={contracts[2].imgURL}
                phone={contracts[2].phone}
                email={contracts[2].email}

            /> */}
        </div>
    );
}

export default App;
