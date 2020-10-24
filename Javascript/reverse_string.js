// Reverse A string.

function reverse(string){
    // Checking the Conditions First.

    if(!string || string.length < 2 || typeof string != 'string' ){
        // If any of the condition satisfies return the string as it is.
        return string;
    } 

    const backward =[];
    const total_item = string.length -1; // bcoz it going to start from 0.

    for(var i = total_item; i >=0 ; i--){
        // Going backwards.
        backward.push(string[i]);
    }

    // Join concatenating the elemnts in the Array.
    return backward.join(''); 
}

// Reverse A string in short methods.

function revShort(string){

    // First it splits the string into Array 
    // Reverse() method bring last element to first 
     // Join concatenating the elemnts in the Array. 
     
    return string.split('').reverse().join('');
}

// Calling Functions.
reverse('Algorithms');

revShort("DataStruct");
