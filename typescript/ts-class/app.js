// type Person = {
//   name: string;
//   age: number;
// }
var add = function (n1, n2) { return n1 + n2; };
var Person = /** @class */ (function () {
    function Person(n) {
        this.age = 30;
        this.name = n;
    }
    Person.prototype.greet = function (phrase) {
        console.log(phrase + ' ' + this.name);
    };
    return Person;
}());
var user1;
user1 = new Person('Max');
console.log(user1);
user1.greet('Hi there - I am');
