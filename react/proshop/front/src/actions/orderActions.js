import { ORDER_CREATE_REQUEST, ORDER_CREATE_SUCCESS, ORDER_CREATE_FAIL, ORDER_DETAILS_SUCCESS, ORDER_DETAILS_FAIL, ORDER_DETAILS_REQUEST, ORDER_PAY_FAIL, ORDER_PAY_SUCCESS, ORDER_PAY_REQUEST, ORDER_LIST_MY_REQUEST, ORDER_LIST_MY_SUCCESS, ORDER_LIST_MY_FAIL, ORDER_LIST_REQUEST, ORDER_LIST_SUCCESS, ORDER_LIST_FAIL, ORDER_DELIVER_SUCCESS, ORDER_DELIVER_REQUEST, ORDER_DELIVER_FAIL } from '../constants/orderConstants'

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

export const getOrderDetails = (id) => async (dispatch, getState) => {
  try {
    dispatch({
      type: ORDER_DETAILS_REQUEST
    })
    const { userLogin: { userInfo } } = getState()

    const config = {
      headers: {
        'Content-Type': 'application/json',
        'Authorization': `Bearer ${userInfo.token}`
      }
    }

    const res = await fetch(`/api/orders/${id}`, config)
    const data = await res.json()

    if(!data.message) {
      dispatch({
        type: ORDER_DETAILS_SUCCESS,
        payload: data
      })
    } else {
      dispatch({
        type: ORDER_DETAILS_FAIL,
        payload: data.response && data.response.data.message ? data.response.data.message : data.message
      })
    }

  } catch(err) {
    dispatch({
        type: ORDER_DETAILS_FAIL,
        payload: err.response && err.response.err.message ? err.response.err.message : err.message
      })
  }
}


export const payOrder = (orderId, paymentResult) => async (dispatch, getState) => {
  try {
    dispatch({
      type: ORDER_PAY_REQUEST
    })
    const { userLogin: { userInfo } } = getState()

    const config = {
      method:'PUT',
      headers: {
        'Content-Type': 'application/json',
        'Authorization': `Bearer ${userInfo.token}`
      },
      body: JSON.stringify(paymentResult)
    }

    const res = await fetch(`/api/orders/${orderId}/pay`, config)
    const data = await res.json()

    if(!data.message) {
      dispatch({
        type: ORDER_PAY_SUCCESS,
        payload: data
      })
    } else {
      dispatch({
        type: ORDER_PAY_FAIL,
        payload: data.response && data.response.data.message ? data.response.data.message : data.message
      })
    }

  } catch(err) {
    dispatch({
        type: ORDER_PAY_FAIL,
        payload: err.response && err.response.err.message ? err.response.err.message : err.message
      })
  }
}

export const listMyOrders = () => async (dispatch, getState) => {
  try {
    dispatch({
      type: ORDER_LIST_MY_REQUEST
    })
    const { userLogin: { userInfo } } = getState()

    const config = {
      headers: {
        'Content-Type': 'application/json',
        'Authorization': `Bearer ${userInfo.token}`
      }
    }

    const res = await fetch(`/api/orders/myorders`, config)
    const data = await res.json()

    if(!data.message) {
      dispatch({
        type: ORDER_LIST_MY_SUCCESS,
        payload: data
      })
    } else {
      dispatch({
        type: ORDER_LIST_MY_FAIL,
        payload: data.response && data.response.data.message ? data.response.data.message : data.message
      })
    }

  } catch(err) {
    dispatch({
        type: ORDER_LIST_MY_FAIL,
        payload: err.response && err.response.err.message ? err.response.err.message : err.message
      })
  }
}

export const listOrders = () => async (dispatch, getState) => {
  try {
    dispatch({
      type: ORDER_LIST_REQUEST
    })
    const { userLogin: { userInfo } } = getState()

    const config = {
      headers: {
        'Content-Type': 'application/json',
        'Authorization': `Bearer ${userInfo.token}`
      }
    }

    const res = await fetch(`/api/orders`, config)
    const data = await res.json()

    if(!data.message) {
      dispatch({
        type: ORDER_LIST_SUCCESS,
        payload: data
      })
    } else {
      dispatch({
        type: ORDER_LIST_FAIL,
        payload: data.response && data.response.data.message ? data.response.data.message : data.message
      })
    }

  } catch(err) {
    dispatch({
        type: ORDER_LIST_FAIL,
        payload: err.response && err.response.err.message ? err.response.err.message : err.message
      })
  }
}

export const deliverOrders = (order) => async (dispatch, getState) => {
  try {
    dispatch({
      type: ORDER_DELIVER_REQUEST
    })
    const { userLogin: { userInfo } } = getState()

    const config = {
      headers: {
        'Authorization': `Bearer ${userInfo.token}`
      }
    }

    const res = await fetch(`/api/orders/${order._id}/deliver`, config)
    const data = await res.json()

    if(!data.message) {
      dispatch({
        type: ORDER_DELIVER_SUCCESS,
        payload: data
      })
    } else {
      dispatch({
        type: ORDER_DELIVER_FAIL,
        payload: data.response && data.response.data.message ? data.response.data.message : data.message
      })
    }

  } catch(err) {
    dispatch({
        type: ORDER_DELIVER_FAIL,
        payload: err.response && err.response.err.message ? err.response.err.message : err.message
      })
  }
}