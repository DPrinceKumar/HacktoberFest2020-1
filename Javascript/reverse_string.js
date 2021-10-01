const reverse = str => str.split('').reverse().join();


//another way of reversing the string

function reverseString(str){
    str = str.split('');
    let outputString = '';
    for(let i =str.length; i > 0; i--){
        outputString += str[i];    
    }
  return outputString.join('');
}
