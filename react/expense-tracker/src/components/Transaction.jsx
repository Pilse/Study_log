import React, { useContext } from 'react';
import { GlobalContext } from './context/GlobalState'

function Transaction({text ,amount, id}) {

    const {deleteTransaction} =useContext(GlobalContext);

    return (
        <>
        <div className={amount>=0? "transaction-list plus":"transaction-list minus"}>
            <button 
            onClick={()=>deleteTransaction(id)}
            className="transaction-delete">x</button>
            <div className="transaction-item">
                {text}
            </div>
            <div className="transaction-pay ">
                {amount>=0?'+':'-'}${Math.abs(amount)}
            </div>
        </div>
        </>
    );
}

export default Transaction;