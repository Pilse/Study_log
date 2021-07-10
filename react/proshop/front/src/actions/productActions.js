import { 
  PRODUCT_LIST_REQUEST,
  PRODUCT_LIST_SUCCESS,
  PRODUCT_LIST_FAIL,
  PRODUCT_DETAILS_REQUEST,
  PRODUCT_DETAILS_SUCCESS,
  PRODUCT_DETAILS_FAIL
 } from "../constants/productConstant";

 export const listProducts = () => async (dispatch) => {
   try {
     dispatch({ type: PRODUCT_LIST_REQUEST })

     const res = await fetch('/api/products')
     const data = await res.json()
    
     if(!data.message) {
      dispatch({
        type: PRODUCT_LIST_SUCCESS,
        payload: data
      })
    } else {
      dispatch({
        type: PRODUCT_LIST_FAIL,
        payload: data.response && data.response.data.message ? data.response.data.message : data.message
      })
    }
    
   } catch (err) {
    dispatch({
      type: PRODUCT_LIST_FAIL,
      payload: err.response && err.response.data.message ? err.response.data.message : err.message
    })
   }
 }

 export const listProductDetails = (id) => async (dispatch) => {
  try {
    dispatch({ type: PRODUCT_DETAILS_REQUEST })

    const res = await fetch(`/api/products/${id}`)
    const data = await res.json()
   
    if(!data.message) {
     dispatch({
       type: PRODUCT_DETAILS_SUCCESS,
       payload: data
     })
   } else {
     dispatch({
       type: PRODUCT_DETAILS_FAIL,
       payload: data.response && data.response.data.message ? data.response.data.message : data.message
     })
   }
   
  } catch (err) {
   dispatch({
     type: PRODUCT_LIST_FAIL,
     payload: err.response && err.response.data.message ? err.response.data.message : err.message
   })
  }
}