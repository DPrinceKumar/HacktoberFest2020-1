const Size_AOS = v => Array.isArray(v)  ? v.length  :
    v && typeof v === 'object' ? v.size || v.length || Object.keys(v).length :
    typeof v === 'string' ? new Blob([v]).size : 0;


console.log(Size_AOS('This is text')); // 12
console.log(Size_AOS({ a: 1, b: 2, c: 3, d: 4, e: 5 })); // 5
console.log(Size_AOS([5, 2, 4, 4, 5,6,77,99])); // 8
