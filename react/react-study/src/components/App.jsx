import React from "react";
import Card from './Card';
import contracts from '../contacts';

function App(props) {
    return (
        <div>
            <h1 className="heading">My Contacts</h1>
            <Card
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

            />
        </div>
    );
}

export default App;
