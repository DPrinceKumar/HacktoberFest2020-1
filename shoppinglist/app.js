// functions :

function add_item(e){
    var user=document.getElementById('input').value;
    var list=document.getElementById('original');
    var update=document.getElementById('product');
    var error_msg=document.getElementById('error');
    var start_msg=document.getElementById('noinput');
    if(user !="" ){
        start_msg.style.setProperty('display','none');
        error_msg.style.setProperty('display','none');

        update.innerHTML=user;
        var clone=list.cloneNode(true);
        clone.classList.add('list1');
        clone.style.setProperty('display', 'flex');
        list.after(clone);
        arrayl.push(clone);
    }

    else{
        error_msg.style.setProperty('display','inline')
    }
}

function remove_element(e){
    if(e.target.classList.contains('delb')){
        var start_msg=document.getElementById('noinput2');
        start_msg.style.setProperty('display','none');
        var cart=document.getElementById('list2');
        arrayr.push(e.target.parentElement)
        cart.appendChild(e.target.parentElement);
        arrayl.pop();
        if(arrayl.length==0){
            var msg=document.getElementById('noinput');
            msg.style.setProperty('display','block');
        }
    }
}

function remove_e(e){
    if(e.target.classList.contains('delb')){
        e.target.parentElement.remove();
        arrayr.pop();
        if(arrayr.length==0){
            var msg=document.getElementById('noinput2');
            msg.style.setProperty('display','block');
        }
    }
}



// Selectors :
var button=document.getElementById('btn');

// Main :
arrayl=[];
arrayr=[];
button.addEventListener("click",add_item);

var items=document.getElementById('l');
var cart_items=document.getElementById('r');
items.addEventListener('click',remove_element);
cart_items.addEventListener('click',remove_e);




