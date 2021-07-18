import { 
  PRODUCT_LIST_REQUEST,
  PRODUCT_LIST_SUCCESS,
  PRODUCT_LIST_FAIL,
  PRODUCT_DETAILS_REQUEST,
  PRODUCT_DETAILS_SUCCESS,
  PRODUCT_DETAILS_FAIL,
  PRODUCT_DELETE_REQUEST,
  PRODUCT_DELETE_SUCCESS,
  PRODUCT_DELETE_FAIL,
  PRODUCT_CREATE_REQUEST,
  PRODUCT_CREATE_SUCCESS,
  PRODUCT_CREATE_FAIL,
  PRODUCT_UPDATE_REQUEST,
  PRODUCT_UPDATE_SUCCESS,
  PRODUCT_UPDATE_FAIL,
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

export const deletProduct = (id) => async (dispatch, getState) => {
  try {
    dispatch({
      type: PRODUCT_DELETE_REQUEST
    })
    const { userLogin: { userInfo } } = getState()

    const config = {
      method: 'DELETE',
      headers: {
        'Authorization': `Bearer ${userInfo.token}`
      }
    }
    
    const res = await fetch(`/api/products/${id}`, config)
    const data = await res.json()

    if(!data.message) {
      dispatch({
        type: PRODUCT_DELETE_SUCCESS,
      })
    } else {
      dispatch({
        type: PRODUCT_DELETE_FAIL,
        payload: data.response && data.response.data.message ? data.response.data.message : data.message
      })
    }

  } catch(err) {
    dispatch({
        type: PRODUCT_DELETE_FAIL,
        payload: err.response && err.response.err.message ? err.response.err.message : err.message
      })
  }
}

export const createProduct = () => async (dispatch, getState) => {
  try {
    dispatch({
      type: PRODUCT_CREATE_REQUEST
    })
    const { userLogin: { userInfo } } = getState()

    const config = {
      method: 'POST',
      headers: {
        'Authorization': `Bearer ${userInfo.token}`
      }
    }
  
    const res = await fetch(`/api/products`, config)
    const data = await res.json()

    if(!data.message) {
      dispatch({
        type: PRODUCT_CREATE_SUCCESS,
        payload: data
      })
    } else {
      dispatch({
        type: PRODUCT_CREATE_FAIL,
        payload: data.response && data.response.data.message ? data.response.data.message : data.message
      })
    }

  } catch(err) {
    dispatch({
        type: PRODUCT_CREATE_FAIL,
        payload: err.response && err.response.err.message ? err.response.err.message : err.message
      })
  }
}

export const updateProduct = (product) => async (dispatch, getState) => {
  try {
    dispatch({
      type: PRODUCT_UPDATE_REQUEST
    })
    const { userLogin: { userInfo } } = getState()

    const config = {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
        'Authorization': `Bearer ${userInfo.token}`
      },
      body:JSON.stringify(product)
    }
  
    const res = await fetch(`/api/products/${product.id}`, config)
    const data = await res.json()

    if(!data.message) {
      dispatch({
        type: PRODUCT_UPDATE_SUCCESS,
        payload: data
      })
    } else {
      dispatch({
        type: PRODUCT_UPDATE_FAIL,
        payload: data.response && data.response.data.message ? data.response.data.message : data.message
      })
    }

  } catch(err) {
    dispatch({
        type: PRODUCT_UPDATE_FAIL,
        payload: err.response && err.response.err.message ? err.response.err.message : err.message
      })
  }
}