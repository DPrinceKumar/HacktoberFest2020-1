/**
 * Implementation of insertion sort
 *
 * @param array
 * @returns array
 */
const insertionSort = (array) => {
  const arrayLength = array.length

  for (let i = 1; i < arrayLength; i++) {
    let j = i - 1
    let temp = array[i]

    while (j >= 0 && array[j] > temp) {
      array[j + 1] = array[j]
      j--
    }

    array[j + 1] = temp
  }
  return array
}
