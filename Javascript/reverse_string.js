//The problem way
let x = '32243';
const y = [...x];
let reverseArray = [];
for (let index = 0; index <= y.length; index++) {
   
   const element = y[y.length-index];
   reverseArray.push(element);
    
}
//const leng = reverseArray.length;
const newRev = reverseArray.slice(1);
const newRevToString = newRev.join('').toString();
//console.log(Number(newRevToString));
//End of Long cut 

// The shortWay
const a = y.reverse().join('').toString();

//console.log(Number(a));


const myArr = [10,5,9,8,2];
const sorted = myArr.sort();



const getSize = ( param )=> {
  const sorted = [...param].sort();
   let newDoubleNum = [];
   let single = [];
for (let index = 0; index < sorted.length; index++) {
   const element = sorted[index];

   if (element > 9) {
      newDoubleNum.push(element);  
   }else{
      single.push(element)
   }
}
  // console.log(newDoubleNum, single);

   const arrangedArray = [...single,...newDoubleNum];
   //console.log(arrangedArray);
   //console.log(arrangedArray[sorted.length - 2] + ' is the second Largest ' + arrangedArray[1] + ' is the second lowest');

}

getSize([1,3,7,4,8,9]);


const dashed = ( param ) => {
   const numArr = [...param];
   const evenArr = [];
   const oddArr = [];
   for (let index = 0; index < numArr.length; index++) {
      const element = array[index];
      if(element % 2 == 1){
         oddArr.push(element);
      }else{
         evenArr.push(element);
      }

      
      
   }
}


const ac = ['babatunde-hameed-olakunle']
const trans = ac.toString()

const xaa = trans.split('-')

console.log(xaa);