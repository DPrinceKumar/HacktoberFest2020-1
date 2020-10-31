const menbtn = document.querySelector('.btn');
let menopen = false;
menbtn.addEventListener('click', () => {
    if(!menopen){
        menbtn.classList.add('open');
        menopen = true;
    }
    else{
        menbtn.classList.remove('open');
        menopen = false;
    }
});
