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

// function bmiCalculator (height,weight){
//     var bmi = height/(weight*weight); // is same with height/Math.pow(height,2);
//     return bmi;
// }

// var bmi = bmiCalculator(65,1.8);
// console.log(Math.round(bmi));

// var n =Math.random()*10;
// console.log(Math.round(n));

// var name1 = prompt("love percentage! first:");
// var name2 = prompt("second:");
// var randomNumber = Math.random()*100+1;
// alert(randomNumber.toFixed(1)+"% !");

// function bmi(weight,height){
//     var BMI = weight/Math.pow(height,2);
//     var interpretation="";
//     if(BMI<18.5)
//         interpretation += "Your BMI is "+BMI+",so you are underweight";
//     else if(BMI>18.5 && BMI <24.9)
//         interpretation += "Your BMI is "+BMI+",so you have noraml weight";
//     else
//         interpretation+="Your BMI is "+BMI+",so you are overweight";

//     return interpretation;
// }
// console.log(bmi(72,1.81));

// function isLeap(year){
//     var isLeap="";
//     if(year%4===0){
//         if(year%100===0){
//             if(year%400===0)
//                 isLeap+="Leap year."
//             else
//                 isLeap+="Not leap year."
//         }
//         else
//             isLeap+="Leap year."
//     }
//     else
//         isLeap+="Not leap year."
//     return isLeap;
// }
// console.log(isLeap(2020));

// var guest =["a","b","c","d","e"];
// var isGuest=prompt("who are you");
// if(guest.includes(isGuest))
//     console.log("welcome");
// console.log(guest.length);
// guest.push("f");
// console.log(guest);
// guest.pop();
// console.log(guest);

// var output=[];
// var index=1;
// function fizzBuzz(){
//     var string="";
//     if(index%3===0)
//         string="Fizz";
//     if(index%5===0)
//         string="Buzz";
//     if(index%3===0&&index%5===0)
//         string="FizzBuzz";

//     if(string.length>0)
//         output.push(string);
//     else
//         output.push(index);
//     index++;
//     console.log(output);
// }

// for(var i=0;i<15;i++){
//     fizzBuzz();
// }

// function whosPaying(names){
//     var randomNumber = Math.floor(Math.random()*(names.length));
//     console.log(randomNumber);
//     return names[randomNumber]+" is going to buy lunch today!";
// }
// console.log(whosPaying(["a","b","c","d","e"]));

// function fibonacciGenerator(n){
//     var first=0;
//     var second=1;
//     var output=[];
//     for(var i=0;i<n;i++)
//     {
//         if(i===0)
//             output.push(first);
//         else if(i===1)
//             output.push(second);
//         else
//             output.push((output[output.length-1])+(output[output.length-2]))
//     }
//     return output;
// }
// output=fibonacciGenerator(5);
// console.log(output);

function Housekeeper (yearsOfExperience,name,cleaningRepertorie){
    this.yearsOfExperience = yearsOfExperience;
    this.name =name;
    this.cleaningRepertorie = cleaningRepertorie;
    this.cleaning = function() {
        alert('cleaning in progress');
    }
}

var houseKeeper1 = new Housekeeper(13,'john',['toilet','bedroom']);
console.log(houseKeeper1);
houseKeeper1.cleaning();