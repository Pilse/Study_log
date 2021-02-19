import { useReducer } from "react"


export default (state,action) =>{
    switch(action.type){
        case 'ADD_TRANSACTION':
            return({
                transactons:[
                    ...state.transactons,
                    {id:action.newTransaction.id, text:action.newTransaction.text, amount:action.newTransaction.amount}
                ]
            });
        case 'DELETE_TRANSACTION':
            console.log(state.transactons);
            return({
                transactons:
                state.transactons.filter((state)=>{
                    return state.id!==action.id;
                })
            
            })
        default:
            return state;
    }
}