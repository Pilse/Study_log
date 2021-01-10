// var message="compose your tweet: "
// var string = prompt(message);
// var maxLength = 140;
// var leftCharacterCount = maxLength-string.length;

// if(leftCharacterCount>=0)
//     console.log("you have written " + string.length + ", you have " + leftCharacterCount + " left." );
// else{
//     console.log("you have written " + (-leftCharacterCount) + " more.");
//     var slicedCharacter = string.slice(0,140);
//     console.log(slicedCharacter);
// }


// var slicedString=string.slice(0,1).toUpperCase();
// console.log("Hello, " + slicedString+string.slice(1,string.length).toLowerCase());
// console.log(3+10/3);

// var humanAge=(string-2)*4+21;
// console.log(humanAge)

// function getMilk(money) {   
//     console.log("leaveHouse");
//     console.log("moveRight");
//     console.log("moveRight");
//     console.log("moveUp");
//     console.log("moveUp");
//     console.log("moveUp");
//     console.log("moveUp");
//     console.log("moveRight");
//     console.log("moveRight");
//     console.log("buy"+Math.floor(money/(1.5))+" bottles of milk.");
//     console.log("moveLeft");
//     console.log("moveLeft");
//     console.log("moveDown");
//     console.log("moveDown");
//     console.log("moveDown");
//     console.log("moveDown");
//     console.log("moveLeft");
//     console.log("moveLeft");
//     console.log("enterHouse");
  
// };
// getMilk(5);

// function lifeInWeeks(age){
//     var ageLeft = 90-age;
//     var ageLeftDays = ageLeft * 365;
//     var ageLeftWeeks = ageLeft * 52;
//     var ageLeftMonths = ageLeft * 12; 
//     console.log("You have "+ageLeftDays+" days, "+ageLeftWeeks+" weeks, and "+ageLeftMonths+" months left.");

// };
// lifeInWeeks(30);

function bmiCalculator (height,weight){
    var bmi = height/(weight*weight); // is same with height/Math.pow(height,2);
    return bmi;
}

var bmi = bmiCalculator(65,1.8);
console.log(Math.round(bmi));