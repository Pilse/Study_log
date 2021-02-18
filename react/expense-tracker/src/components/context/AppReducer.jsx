import { useReducer } from "react"


export default (state,action) =>{
    switch(action.type){
        case 'ADD_TRANSACTION':
            return(
                {transactons:[
                    ...state.transactons,
                    {id:action.newTransaction.id, text:action.newTransaction.text, amount:action.newTransaction.amount}
                ]
            }
            );
        case 'DELETE_TRANSACTION':
            return(
                state.filter((state,idx)=>{
                    return idx!==action.id;
                })
            )
        default:
            return state;
    }
}