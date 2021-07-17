import { USER_DETAILS_FAIL, USER_DETAILS_REQUEST, USER_DETAILS_SUCCESS, USER_LOGIN_FAIL, USER_LOGIN_REQUEST, USER_LOGIN_SUCCESS, USER_LOGOUT, USER_REGISTER_FAIL, USER_REGISTER_REQUEST, USER_REGISTER_SUCCESS, USER_UPDATE_PROFILE_FAIL, USER_UPDATE_PROFILE_REQUEST, USER_UPDATE_PROFILE_SUCCESS, USER_DETAILS_RESET, USER_LIST_SUCCESS, USER_LIST_REQUEST, USER_LIST_FAIL, USER_LIST_RESET, USER_DELETE_REQUEST, USER_DELETE_SUCCESS, USER_DELETE_FAIL, USER_UPDATE_REQUEST, USER_UPDATE_SUCCESS, USER_UPDATE_FAIL } from "../constants/userConstants"
import { ORDER_LIST_MY_RESET } from '../constants/orderConstants'

export const login = (email, password) => async (dispatch) => {
  try {
    dispatch({
      type: USER_LOGIN_REQUEST
    })

    const config = {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json'
      },
      body: JSON.stringify({
        email,
        password
      })
    }

    const res = await fetch('/api/users/login', config)
    const data = await res.json()

    if(!data.message) {
      dispatch({
        type: USER_LOGIN_SUCCESS,
        payload: data
      })
      localStorage.setItem('userInfo', JSON.stringify(data))

    } else {
      dispatch({
        type: USER_LOGIN_FAIL,
        payload: data.response && data.response.data.message ? data.response.data.message : data.message
      })
    }

  } catch(err) {
    dispatch({
        type: USER_LOGIN_FAIL,
        payload: err.response && err.response.err.message ? err.response.err.message : err.message
      })
  }
}

export const logout = () => (dispatch) => {
  localStorage.removeItem('userInfo')
  dispatch({ type: USER_LOGOUT })
  dispatch({ type: USER_DETAILS_RESET })
  dispatch({ type: ORDER_LIST_MY_RESET })
  dispatch({ type: USER_LIST_RESET })
}

export const register = (name, email, password) => async (dispatch) => {
  try {
    dispatch({
      type: USER_REGISTER_REQUEST
    })

    const config = {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json'
      },
      body: JSON.stringify({
        name,
        email,
        password
      })
    }

    const res = await fetch('/api/users', config)
    const data = await res.json()

    if(!data.message) {
      dispatch({
        type: USER_REGISTER_SUCCESS,
        payload: data
      })

      dispatch({
        type: USER_LOGIN_SUCCESS,
        payload: data
      })

      localStorage.setItem('userInfo', JSON.stringify(data))

    } else {
      dispatch({
        type: USER_REGISTER_FAIL,
        payload: data.response && data.response.data.message ? data.response.data.message : data.message
      })
    }

  } catch(err) {
    dispatch({
        type: USER_REGISTER_FAIL,
        payload: err.response && err.response.err.message ? err.response.err.message : err.message
      })
  }
}

export const getUserDetails = (id) => async (dispatch, getState) => {
  try {
    dispatch({
      type: USER_DETAILS_REQUEST
    })

    const { userLogin: { userInfo } } = getState()

    const config = {
      headers: {
        'Content-Type': 'application/json',
        'Authorization': `Bearer ${userInfo.token}`
      },

    }

    const res = await fetch(`/api/users/${id}`, config)
    const data = await res.json()

    if(!data.message) {
      dispatch({
        type: USER_DETAILS_SUCCESS,
        payload: data
      })
    } else {
      dispatch({
        type: USER_DETAILS_FAIL,
        payload: data.response && data.response.data.message ? data.response.data.message : data.message
      })
    }

  } catch(err) {
    dispatch({
        type: USER_DETAILS_FAIL,
        payload: err.response && err.response.err.message ? err.response.err.message : err.message
      })
  }
}

export const updateUserProfile = (user) => async (dispatch, getState) => {
  try {
    dispatch({
      type: USER_UPDATE_PROFILE_REQUEST
    })
    const { userLogin: { userInfo } } = getState()

    const config = {
      method: 'PUT',
      headers: {
        'Content-Type': 'application/json',
        'Authorization': `Bearer ${userInfo.token}`
      },
      body: JSON.stringify(user)
    }

    const res = await fetch('/api/users/profile', config)
    const data = await res.json()

    if(!data.message) {
      dispatch({
        type: USER_UPDATE_PROFILE_SUCCESS,
        payload: data
      })
    } else {
      dispatch({
        type: USER_UPDATE_PROFILE_FAIL,
        payload: data.response && data.response.data.message ? data.response.data.message : data.message
      })
    }

  } catch(err) {
    dispatch({
        type: USER_UPDATE_PROFILE_FAIL,
        payload: err.response && err.response.err.message ? err.response.err.message : err.message
      })
  }
}

export const listUsers = () => async (dispatch, getState) => {
  try {
    dispatch({
      type: USER_LIST_REQUEST
    })
    const { userLogin: { userInfo } } = getState()

    const config = {
      headers: {
        'Authorization': `Bearer ${userInfo.token}`
      },
    }

    const res = await fetch('/api/users', config)
    const data = await res.json()

    if(!data.message) {
      dispatch({
        type: USER_LIST_SUCCESS,
        payload: data
      })
    } else {
      dispatch({
        type: USER_LIST_FAIL,
        payload: data.response && data.response.data.message ? data.response.data.message : data.message
      })
    }

  } catch(err) {
    dispatch({
        type: USER_LIST_FAIL,
        payload: err.response && err.response.err.message ? err.response.err.message : err.message
      })
  }
}

export const deleteUser = (id) => async (dispatch, getState) => {
  try {
    dispatch({
      type: USER_DELETE_REQUEST
    })
    const { userLogin: { userInfo } } = getState()

    const config = {
      method:'DELETE',
      headers: {
        'Authorization': `Bearer ${userInfo.token}`
      },
    }

    const res = await fetch(`/api/users/${id}`, config)
    const data = await res.json()


    if(!data.message) {
      dispatch({ type: USER_DELETE_SUCCESS })
    } else {
      dispatch({
        type: USER_DELETE_FAIL,
        payload: data.response && data.response.data.message ? data.response.data.message : data.message
      })
    }

  } catch(err) {
    dispatch({
        type: USER_DELETE_FAIL,
        payload: err.response && err.response.err.message ? err.response.err.message : err.message
      })
  }
}


export const updateUser = (user) => async (dispatch, getState) => {
  try {
    dispatch({
      type: USER_UPDATE_REQUEST
    })
    const { userLogin: { userInfo } } = getState()

    const config = {
      method:'PUT',
      headers: {
        'Content-Type': 'application/json',
        'Authorization': `Bearer ${userInfo.token}`
      },
      body: JSON.stringify(user)
    }

    const res = await fetch(`/api/users/${user._id}`, config)
    const data = await res.json()

    if(!data.message) {
      dispatch({ type: USER_UPDATE_SUCCESS })
      dispatch({ type: USER_DETAILS_SUCCESS, payload: data })
    } else {
      dispatch({
        type: USER_UPDATE_FAIL,
        payload: data.response && data.response.data.message ? data.response.data.message : data.message
      })
    }

  } catch(err) {
    dispatch({
        type: USER_UPDATE_FAIL,
        payload: err.response && err.response.err.message ? err.response.err.message : err.message
      })
  }
}