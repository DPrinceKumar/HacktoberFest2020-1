// filters array by function and return only values which are not meet the condition
const filter = (cond, arr) => arr.filter((...arg) => !cond(...arg));


// example - filter array and return words which have capital first letter
console.log(filter(w => w[0] === w[0].toLowerCase(), ['ask', 'Adam','car','Bell','town', 'Computer', 'Javascript']));
// ["Adam", "Bell", "Computer", "Javascript"]