// Sort and Merge an Array.

function mergeSort(array1, array2){

    // Checking if the array1,2 exists or not.
    if(array1.length === 0){
        return array2;
    } 

    if(array2.length === 0){
        return array2;
    }

    const MergedArray= [];
    let array1item = array1[0];
    let array2item = array2[0];
    let i,j = 1;

    while(array1item || array2item){
        if(array2item === undefined || array1item < array2item){
            MergedArray.push(array1item);
            array1item = array1[i];
            i++;
        } else{
                MergedArray.push(array2item);
                array2item = array2[j];
                j++;
        }

    }
    return MergedArray;
}

mergeSort([9,8,7,6],[5,4,3,2,1]);

