
let d,h,m,s,animate;

function init() {
    d=new Date();
    h=d.getHours();
    m=d.getMinutes();
    s=d.getSeconds();

    updateHour();
    
    clock();
}

function updateHour() {
    ampm=h > 12 ? 'pm' : 'am';

    if(h==24){
        h=12;
    }
    if(h>12) {
        h=h-12;
    }

}

function clock() {
    s++;

    if(s==60) {
        s=0;
        m++;
        if(m==60) {
            m=0;
            h++;
            updateHour();
        }
    }
    $('sec', s);
    $('min', m);
    $('hr', h);
    $('ampm', ampm)
    animate=setTimeout(clock, 1000);
}

function $(id, val){
    if(val<10){
        val='0'+val;
    }
    
    document.getElementById(id).innerHTML=val;
}

window.onload=init;