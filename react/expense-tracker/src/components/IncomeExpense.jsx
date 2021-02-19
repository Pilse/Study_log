import React, { useContext } from 'react';
import { GlobalContext } from './context/GlobalState';

function IncomeExpense () {

    const {transactons} = useContext(GlobalContext);
    console.log(transactons);
    let amountArr = transactons.filter(transaction=>{
        return transaction.amount>=0;
    });
    amountArr = amountArr.map(amountArr=>amountArr.amount);

    let minusArr = transactons.filter(transaction=>{
        return transaction.amount<0;
    });
    minusArr = minusArr.map(minusArr=>minusArr.amount);

    const plusTotal = amountArr.reduce((acc,cur)=>{return acc=acc+cur},0).toFixed(2);
    const minusTotal = minusArr.reduce((acc,cur)=>{return acc=acc+cur},0).toFixed(2);

    return(
        <div className="incomeExpense-container">
            <div className="split left">
                INCOME
                <div className="income">${plusTotal}</div>
            </div>
            <div className="split right">
                EXPENSE
            <div className="expense">${Math.abs(minusTotal).toFixed(2)}</div>
            </div>
        </div>
    );
}

export default IncomeExpense;