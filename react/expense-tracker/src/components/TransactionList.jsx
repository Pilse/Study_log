import React, { useContext } from 'react';
import Transaction from './Transaction';
import { GlobalContext } from './context/GlobalState'

function TransactionList() {

    const {transactons} =useContext(GlobalContext);

    return (
        <div className="transaction-container">
            <p>HISTORY</p>
            <div className="transaction">
                <div className="transaction-lists">
                {transactons.map(transacton=>
                    <Transaction 
                        key={transacton.id}
                        text={transacton.text}
                        amount={transacton.amount}
                    />)}
                </div>
            </div>
        </div>
    );
}

export default TransactionList;