let lengthOfLongestSubstring=(s)=>{
    //console.log(s);
    let arr=[];
    //console.log('arr',arr);
    for(let i=0;i<s.length;i++){
        console.log(s[i]);
        if(s[i] == arr[i]){
            return
        }else{
            arr.push(s[i])
        }
    }
    
    console.log('answer',arr);
    
    }
    
    lengthOfLongestSubstring('abcabc');