// Using Javascript filter array method
// filter() method takes each element in an array and it applies a conditional statement against it

const numbers = [1, 2, 3, 4];
const evens = numbers.filter(item => item % 2 === 0);
console.log(evens); // [2, 4]