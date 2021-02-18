import React from 'react';
import Header from './Header';
import Balance from './Balance';
import IncomeExpense from './IncomeExpense';
import TransactionList from './TransactionList';
import CreateTransaction from './CreateTransaction';
import { GlobalProvider } from './context/GlobalState';


function App () {
    return(
        <GlobalProvider> 
            <div className="container">
                <Header />
                <Balance />
                <IncomeExpense />
                <TransactionList />
                <CreateTransaction />
            </div>
        </GlobalProvider>
    );
}

export default App;