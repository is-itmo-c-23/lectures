#include <iostream>
#include <vector>


// 1й полупоток
// template<typename T, size_t SIZE>
// class CStackAllocator {
// public:
//     typedef size_t size_type ;
//     typedef ptrdiff_t difference_type ;
//     typedef T* pointer ;
//     typedef const T* const_pointer ;
//     typedef T& reference ;
//     typedef const T& const_reference ;
//     typedef T value_type ;


//     template<typename U>
//     struct rebind
//     {
//         typedef CStackAllocator<T, SIZE> other;
//     };


//     pointer allocate(size_type n) {
//         pointer result = buffer_ + size_;

//         std::cout << "Allocate " << result << "  " <<  n << std::endl;
//         size_ += n;

//         return result;
//     }

//     void deallocate(pointer p, size_type n) {
//         std::cout << "Deallocate " << p << " " << n << std::endl;
//     }

// private:
//     T buffer_[SIZE];
//     size_t size_ = 0;


// };

// int main(int, char**){
//     std::vector<int, CStackAllocator<int, 100>> v;


//     for(int i = 0; i < 10; ++i)
//         v.push_back(i);


// }



// 2й полупоток
int main(int, char**){


    
}
