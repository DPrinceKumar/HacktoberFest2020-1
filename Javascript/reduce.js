// Using Javascript reduce array method
// reduce() method reduces an array of values down to just one value.

const numbers = [1, 2, 3, 4];
const sum = numbers.reduce(function (result, item) {
  return result + item;
}, 0);
console.log(sum); // 10