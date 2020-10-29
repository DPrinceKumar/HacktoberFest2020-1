#include <iostream>

template <typename T>
void rotate(T* arr, std::size_t n, std::size_t k) {
    if (k > n)
        return;
    
    T* tmp = new int[k];
    for (auto i = 0ul; i < k; ++i)
        tmp[i] = arr[i];

    auto i = 0ul;
    for (; i < n - k; ++i)
        arr[i] = arr[i + k];
    for (; i < k; ++i)
        arr[i] = tmp[i - n];
    delete[] tmp;
}

template <typename T>
std::ostream& print(const T* const arr, std::size_t sz) {
    if (sz == 0) {
        std::cout << "<empty array>" << std::endl;
        return std::cout;
    }
    std::cout << "[ ";
    for (auto i = 0ul; i < sz - 1; i++)
        std::cout << arr[i] << " , ";
    std::cout << arr[sz - 1];
    std::cout << " ]";

    return std::cout;
}

int main() {
    int data[7] = {1, 2, 3, 4, 5, 6, 7};

    std::cout << "Before Rotation: ";
    print(data, 7) << std::endl;

    rotate(data, 7, 2);

    std::cout << "After Rotation: ";
    print(data, 7) << std::endl;

    return 0;
}
