//Capitalizes the first letter of a string.
const BigFL=([f, ...r]) => f.toUpperCase()+r.join('').toLowerCase();

//example :
console.log(BigFL('THIS IS EXAMPLE TEXT')); // 'This is example text'