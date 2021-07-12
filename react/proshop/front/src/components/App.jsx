import React from 'react'
import { Container } from 'react-bootstrap'
import { BrowserRouter as Router, Route } from 'react-router-dom'
import Header from './Header'
import Footer from './Footer'
import HomeScreen from '../screens/HomeScreen'
import ProductScreen from '../screens/ProductScreen'
import CartScreen from '../screens/CartScreen'
import LoginScreen from '../screens/LoginScreen'
import RegisterScreen from '../screens/RegisterScreen'
import ProfileScreen from '../screens/ProfileScreen'
import ShippingScreen from '../screens/ShippingScreen'
import PaymentScreen from '../screens/PaymentScreen'
import PlaceOrderScreen from '../screens/PlaceOrderScreen'

const App = () => {
  return (
    <Router>
      <Header />
        <main className="py-3">
          <Container>
            <Route path='/' exact component={HomeScreen} />
            <Route path='/shipping' exact component={ShippingScreen} />
            <Route path='/payment' exact component={PaymentScreen} />
            <Route path='/placeorder' exact component={PlaceOrderScreen} />
            <Route path='/register' exact component={RegisterScreen} />
            <Route path='/profile' exact component={ProfileScreen} />
            <Route path='/login'  component={LoginScreen} />
            <Route path='/product/:id' exact component={ProductScreen} />
            <Route path='/cart/:id?' exact component={CartScreen} />
          </Container>
        </main>
      <Footer />
    </Router>
  )
}

export default App