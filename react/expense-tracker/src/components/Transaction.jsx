import React from 'react';

function Transaction({text ,amount}) {
    return (
        <div className={amount>=0? "transaction-list plus":"transaction-list minus"}>
            <div className="transaction-item">
                {text}
            </div>
            <div className="transaction-pay ">
                {amount>=0?'+':'-'}${Math.abs(amount)}
            </div>
        </div>
    );
}

export default Transaction;