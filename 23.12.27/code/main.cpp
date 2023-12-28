#include <iostream>

// template<class T, class R>
// const R& max(const T& a, const R& b) {
//     return a > b ? a : b;
// }



// const int& max(const double& a, const int& b) {
//     return a > b ? a : b;
// }


// const double& max(const int& a, const double& b) {
//     return a > b ? a : b;
// }


// const double& max(const double& a, const double& b) {
//     return a > b ? a : b;
// }


template<class T>
const T& max(const T& a, const T& b) {
    return a > b ? a : b;
}


class Foo{};


template<typename T, size_t SIZE>
class CArray {
public:
    T& operator[](size_t index) { return arr[index]; }
    const T& operator[](size_t index) const { return arr[index]; }
    bool empty() const { return SIZE == 0; }
    size_t size() const { return SIZE;}
private:
    T arr[SIZE];
};


template<typename T, size_t SIZE>
void printArray(const CArray<T, SIZE>& arr) {
    for(int i = 0; i < SIZE; ++i)
        std::cout << arr[i];
}

int main(int, char**){
    CArray<int, 10> arr10;
    printArray(arr10);



    // std::cout << max(3.1, 2) << std::endl; // max(doble, int)
    // std::cout << max<double, double>(4, 3.1) << std::endl; // max(int, double)



    return 0;
}
