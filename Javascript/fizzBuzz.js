// Given a positive integer A, return an array of strings with all the integers from 1 to N. But for multiples of 3 the array should have “Fizz” instead of the number. For the multiples of 5, the array should have “Buzz” instead of the number. For numbers which are multiple of 3 and 5 both, the array should have "FizzBuzz" instead of the number.
function fizzBuzz(A){  
		let out = [];
		for(let num = 1; num <= A; num++){
			let remainderBy5 = num % 5;
			let remainderBy3 = num % 3;
			if((!remainderBy5) && (!remainderBy3) ){
				out.push( "FizzBuzz");
			}else if(!remainderBy3){
				out.push( "Fizz");
			}else if(!remainderBy5){
				out.push( "Buzz");
			}else{
				out.push(num);
			}
		}    
		return out;		
	}

let A = 5;
console.log(fizzBuzz(A));