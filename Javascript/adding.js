const add = (numbers) => {
    const x = [...numbers]

    return x.reduce( (a,b) => a+b, 0 )
}
