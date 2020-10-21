
const reverse = (method='long', string) => {
    y = [...string]
    if(method==='long'){
        return y.reverse().join('').toString();
    }else{
        let reverseArray = [];
        for (let index = 0; index <= y.length; index++) {
        
        const element = y[y.length-index];
        reverseArray.push(element);
            
        }
        //const leng = reverseArray.length;
        const newRev = reverseArray.slice(1);
        const newRevToString = newRev.join('').toString();
        return newRevToString
    }
}


