import React, { useContext, useState } from 'react';
import { GlobalContext } from './context/GlobalState';

function CreateTransaction() {
    const [text,setText] = useState('');
    const [amount,setAmount] = useState('');
    const { addTransaction } = useContext(GlobalContext);

    function handleSubmit (e){
        e.preventDefault();
        addTransaction(text,+amount);
        setText('');
        setAmount('');
    }

    return (
        <div className="createTransaction-container">
            <p>Add new transaction</p>
            <form onSubmit={handleSubmit}>
                <div className="input-control">
                    <label>Text</label>
                    <input type="text" placeholder="Enter text..."  onChange={(e)=>setText(e.target.value)} value={text}/>
                </div>
                <div className="input-control">
                    <label>Amount</label>
                    <input type="text" placeholder="Enter amount..." onChange={(e)=>setAmount(e.target.value)} value={amount}/>
                </div>
                <button className="btn">
                    Add transaction
                </button>
            </form>
        </div>
    );
}

export default CreateTransaction;