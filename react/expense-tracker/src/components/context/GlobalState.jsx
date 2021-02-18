import React, { useReducer, createContext } from 'react';
import AppReducer from './AppReducer'


const initialState = {
    transactons: [
        { id: 1, text: 'Cash', amount: 500 },
        { id: 2, text: 'Book', amount: -40 }
    ]
};


export const GlobalContext = createContext(initialState);
export const GlobalProvider = ({ children }) => {
    const [state, dispatch] = useReducer(AppReducer, initialState);
    function addTransaction( text, amount ) {
        dispatch({
            type: 'ADD_TRANSACTION',
            newTransaction: {
                id: Math.random() * 1000000 + 2,
                text:text,
                amount:amount
            }
        })
    }

    function deleteTransaction({ id }) {
        dispatch({
            type: 'DELETE_TRANSACTION',
            id
        })
    }
    return (
        <GlobalContext.Provider value={{
                transactons: state.transactons,
                addTransaction,
                deleteTransaction
            }}>
            {children}
        </GlobalContext.Provider>
    )
}