import React,{ useContext } from 'react';
import { GlobalContext } from './context/GlobalState'

function Balance () {
    const {transactons} = useContext(GlobalContext);
    
    const amountArr = transactons.map(transaction=>{
        return transaction.amount;
    });
    console.log(amountArr);
    const total = amountArr.reduce((acc,cur)=>{return acc=acc+cur},0).toFixed(2);
    return(
        <div className='balance-container'>
            <p>YOUR BALANCE</p>
            <div className="balance-total">
                ${total}
            </div>
        </div>
    );
}

export default Balance;