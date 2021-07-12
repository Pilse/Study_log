import { ORDER_CREATE_REQUEST, ORDER_CREATE_SUCCESS, ORDER_CREATE_FAIL } from '../constants/orderConstants'

export const createOrder = (order) => async (dispatch, getState) => {
  try {
    dispatch({
      type: ORDER_CREATE_REQUEST
    })
    const { userLogin: { userInfo } } = getState()

    const config = {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
        'Authorization': `Bearer ${userInfo.token}`
      },
      body: JSON.stringify(order)
    }

    const res = await fetch('/api/orders', config)
    const data = await res.json()

    if(!data.message) {
      dispatch({
        type: ORDER_CREATE_SUCCESS,
        payload: data
      })
    } else {
      dispatch({
        type: ORDER_CREATE_FAIL,
        payload: data.response && data.response.data.message ? data.response.data.message : data.message
      })
    }

  } catch(err) {
    dispatch({
        type: ORDER_CREATE_FAIL,
        payload: err.response && err.response.err.message ? err.response.err.message : err.message
      })
  }
}