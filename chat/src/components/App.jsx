
import { BrowserRouter as Router, Route, Switch} from 'react-router-dom';
import Login from './Login';
import Header from './Header';
import Rooms from './Rooms';
import Chat from './Chat';



function App() {
    return (
        
        <Router>
            <Header />
            <Route path='/' exact > <Rooms /></Route>
            <Route path='/login' exact> <Login /> </Route>
            <Switch>
                <Route path='/chat/:name/' exact><Chat /></Route>
            </Switch>
        </Router>
    );
}

export default App;
