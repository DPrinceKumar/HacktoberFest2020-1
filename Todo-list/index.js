
var togglecheck =function(){
    let parent =this.parentNode
    parent.classList.toggle('checked')
}


var deleteitem =function()
{
    let parent =this.parentNode;
    var c = parent.childNodes
    var index = itemsArray.indexOf(c[1].innerHTML)
    console.log(c[1].innerHTML)

    labelvalue =c[1].innerHTML
    
    parent.remove();
    itemsArray.splice(index,1)
    localStorage.setItem('items', JSON.stringify(itemsArray))
}

var createtodo =function(todo){
    let li =document.createElement('li')
    let label = document.createElement('label')
    label.innerHTML =todo;
  

    let checkbox = document.createElement('input')
    checkbox.type ='checkbox'
    checkbox.className ='check'
    checkbox.onclick =togglecheck;
    

    let deletebtn = document.createElement('button')
    deletebtn.innerHTML = "delete"
    deletebtn.className = 'theme delete'
    
    deletebtn.onclick =deleteitem;

    li.appendChild(checkbox);
    li.appendChild(label)
    li.appendChild(deletebtn);
    return li;
}



let itemsArray =localStorage.getItem('items')?JSON.parse(localStorage.getItem('items')):[]

localStorage.setItem('items', JSON.stringify(itemsArray))
const data =JSON.parse(localStorage.getItem('items'))

var list =document.querySelector('#list');

data.forEach(element => {
    list.appendChild(createtodo(element))
});


var test =function() {
    var list =document.querySelector('#list');
    
    let inputtext =document.getElementById('inputbox').value;

    if(inputtext!== "")
    {
        itemsArray.push(inputtext)
        localStorage.setItem('items', JSON.stringify(itemsArray))

        list.appendChild(createtodo(inputtext));
        document.getElementById('inputbox').value =" ";
    }
    else{
        return;
    }
}

var currenttheme='rgb(116, 116, 231)'
function themechange() {
    var theme2 = document.querySelectorAll('.theme')
    var newtheme= randomcolor()
    currenttheme =newtheme;
    // var newtheme2 = randomcolor()
    for (var i = 0; i < theme2.length; i++) {
        theme2[i].style.backgroundColor = newtheme;
        // theme2.style.backgroundimage = lineargradient(newtheme,newtheme2)
    }
    // theme2[2].style.color =randomcolor()

   
}

var rand = function(){
    return Math.round(Math.random()*255 +1)
}
var randomcolor= function(){
    
    return 'rgb('+rand()+","+ rand() + ","+ rand() + ")"
}

let themearray = localStorage.getItem( 'color')?JSON.parse(localStorage.getItem('color')):[]
function savetheme(){
    themearray.push(currenttheme)
    console.log(currenttheme)

    localStorage.setItem('color',JSON.stringify(themearray))
}
var id=0;

function applysaved(){
    if(themearray.length===0)
    alert('No saved themes')
var themenow =document.querySelectorAll('.theme')
if(id===themearray.length)
id=0;
for (var i = 0; i < themenow.length; i++) {
    themenow[i].style.backgroundColor = themearray[id];
    // theme2.style.backgroundimage = lineargradient(newtheme,newtheme2)
}
id++
console.log(themearray.length)
}

function cleartheme(){
    themearray=[];
    localStorage.setItem('color',JSON.stringify(themearray))
}
