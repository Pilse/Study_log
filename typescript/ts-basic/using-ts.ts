const button = document.querySelector("button");
const input1 = <HTMLInputElement>document.getElementById("num1")!;
const input2 = <HTMLInputElement>document.getElementById("num2")!;

function add(num1: number, num2: number) {
  return num1 + num2;
}

button.addEventListener("click", function () {
  console.log(add(+input1.value, +input2.value));
});
