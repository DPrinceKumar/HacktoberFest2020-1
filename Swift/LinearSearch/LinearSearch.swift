import Foundation

var arr = [100, 3000, 400, 55, 120, 3, 700, 222]

func linearSearch<T: Equatable>(array: [T], target: T ) -> Int? {
    for (index, item) in array.enumerated() {
        if item == target {
            return index
        }
    }
    return -1
}

print("Normal Array: \(arr)")
print("Linear Search index: \(linearSearch(array: arr, target: 55) ?? -1)")
