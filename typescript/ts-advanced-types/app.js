// interface Admin {
//   name: string;
//   privileges: string[];
// };
var _a;
var e1 = {
    name: 'Max',
    privileges: ['create-server'],
    startDate: new Date()
};
function add(a, b) {
    if (typeof a === 'string' || typeof b === 'string') {
        return a.toString() + b.toString();
    }
    return a + b;
}
var result = add('Max', ' Schwarz');
result.split(' ');
var fetchedUserData = {
    id: 'u1',
    name: 'Max',
    job: {}
};
console.log((_a = fetchedUserData === null || fetchedUserData === void 0 ? void 0 : fetchedUserData.job) === null || _a === void 0 ? void 0 : _a.title);
var userInput = '';
var storedData = userInput !== null && userInput !== void 0 ? userInput : 'DEFAULT';
function printEmployeeInformation(emp) {
    console.log('Name: ' + emp.name);
    if ('privileges' in emp) {
        console.log('Privileges ' + emp.privileges);
    }
    if ('startDate' in emp) {
        console.log('Start Date ' + emp.startDate);
    }
}
printEmployeeInformation({ name: 'Max', startDate: new Date() });
var Car = /** @class */ (function () {
    function Car() {
    }
    Car.prototype.drive = function () {
        console.log('Driving...');
    };
    return Car;
}());
var Truck = /** @class */ (function () {
    function Truck() {
    }
    Truck.prototype.drive = function () {
        console.log('Driving a truck');
    };
    Truck.prototype.loadCargo = function (amount) {
        console.log('Loading cargo ...' + amount);
    };
    return Truck;
}());
var v1 = new Car();
var v2 = new Truck();
function useVehicle(vehicle) {
    vehicle.drive();
    if (vehicle instanceof Truck) {
        vehicle.loadCargo(1000);
    }
}
useVehicle(v1);
useVehicle(v2);
function moveAnimal(animal) {
    var speed;
    switch (animal.type) {
        case 'bird':
            speed = animal.flyingSpeed;
            break;
        case 'horse':
            speed = animal.runningSpeed;
            break;
    }
    console.log('Moving Speed: ' + speed);
}
moveAnimal({ type: 'bird', flyingSpeed: 10 });
// const userInputElement = <HTMLInputElement>document.getElementById('user-input');
var userInputElement = document.getElementById('user-input');
userInputElement.value = 'Hi there!';
var errorBag = {
    email: 'Not a valid email!',
    username: 'Must start with a capital character!'
};
