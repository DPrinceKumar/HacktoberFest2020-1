const count = ar =>   ar.reduce((el, i) => { 
    el[i] = el[i] ? el[i] + 1 : 1; 
    return el;
  }, {});
  
  console.log(count(['aa','aa', 'cc','aa','cc','dd','cc','hh','hh','cc','dd','hh','hh'])); 
  // {
  //aa: 3,
  //cc: 4,
  //dd: 2,
  //hh: 4
  //}