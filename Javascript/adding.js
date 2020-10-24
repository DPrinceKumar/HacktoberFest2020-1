// function add(a,b){
// return a,b
// }
// function(10,5)

// function that adds two numbers together or more

const add = (numbers) => {
    const x = [...numbers]

    return x.reduce( (a,b) => a+b, 0 )
}