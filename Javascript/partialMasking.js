
const partialWordMask = (value, position=2, postfix='*') => {
   return `${value.substring(0, position)}${value.substring(position).replace(/\S/g, postfix)}`
}


