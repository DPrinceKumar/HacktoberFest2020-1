// Checking if array is sorted
// Working even elements are repeated

const isSort = arr => {
    if (arr.length <= 1) return "Array is too small";
    const idx = arr.findIndex( (val,id,arr) =>  val != arr[0]);  
    const AscDesc = arr[idx] - arr[idx-1];
    for (let i = idx; i < arr.length; i++) {
        if ((arr[i] - arr[i - 1]) * AscDesc < 0) return "Array not sorted";
    }
      return  AscDesc > 0 ? "Array is sorted Ascending" : "Array is sorted Descending"
  };



//example
console.log(isSort([1,1,1,3,4,7,9,57])); // "Array is sorted Ascending"