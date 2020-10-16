   const numbers = [1,2,3,4];
console.log(move(numbers,1,-1)) ;// move(arrau,index,offset)

function move(array,index,offset){
    const position = index+offset;
    if(position >= array.length || position < 0){
        console.log("invalid offset ");
        return;
    }
    const element = array.splice(index,1)[0];
    const cloneArray = [...array];
    cloneArray.splice(position,0,element);
    return cloneArray;
}
//  input is [1,2,3,4]
//  we want no at index -1(i.e. 2) to move back by offset 2 
//  ouput is: [2,1,3,4]