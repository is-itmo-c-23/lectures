#include <iostream>
#include <functional>


// 2й полупоток
// bool greater(int a, int b) {
//     return a > b;
// }


// struct Grater {
//     bool operator()(int a, int b) const {
//          return a > b;
//     }
// };


// //using TComparer = bool(*)(int, int);


// template<typename TComparer>
// int findMax(int* array, size_t size, TComparer compare) {
//     int result = array[0];
//     for(int i = 1; i < size; ++i) {
//         if(compare(array[i], result))
//             result = array[i];
//     }

//     return result;
// }

// class GreaterThen {
// public:
//     GreaterThen(int limit)
//         : limit_(limit)
//     {}

//     bool operator()(int value) const {
//         return value > limit_;
//     }
// private:
//     int limit_;
// };

// class GreaterThen4 {
// public:
//      bool operator()(int value) const {
//         return greater(value);
//     }
// private:
//     GreaterThen greater{4};
// };


// int main(int, char**){

//     std::vector<int> v = {1,2,3,4,5,6,7};

//     auto it = std::find_if(v.begin(), v.end(), GreaterThen{4});
//     //auto it = std::find_if(v.begin(), v.end(), std::greater<int>{});

//     auto it = std::find_if(v.begin(), v.end(), [](int value) -> bool { return value > 4;});


//     std::bind(std::greater<int>{}, std::placeholders::_1, 4);

//    std::bind1st




//     if(it != v.end())
//         std::cout << *it;


//     // int array[] = {1, 4, 2, 3, 9, 7};

//     // bool(*funcPtr)(int, int) = greater;

//     // std::cout << findMax(array, sizeof(array)/sizeof(int), greater) << std::endl;
//     // std::cout << findMax(array, sizeof(array)/sizeof(int), Grater{}) << std::endl;


// }


// 1й полупоток


int incr(int value ) {
    return value + 1;
}

// using TComparer = bool(*)(int, int);


template<typename TComparer>
int findMax(int* array, size_t size, TComparer compare) {
    int result = array[0];

    for(int i = 1; i < size; ++i) {
        if(compare(array[i], result))
            result = array[i];
    }

    return result;
}


bool greater(int a, int b) {
    return a > b;
}


struct  Greater {
    bool operator()(int a, int b) const {
        return a > b;
    }
};


bool less(int a, int b) {
    return a < b;
}

class GreaterThen {
public:
    GreaterThen(int limit)
        : limit_(limit)
    {}

    bool operator()(int value) const {
        return value > limit_;
    }

private:
    int limit_;
};



template<typename T, typename U>
struct SimpleOverloader : public T, U {
    SimpleOverloader(T t, U u) : T(t), U(u)
        {}
    using T::operator();
    using U::operator();
};

template<typename T, typename U>
SimpleOverloader<T,U> MakeOverloaded(
    const T& t, const U& u
){
    return SimpleOverloader<T, U>(t, u);
}


int main() {

    auto o = MakeOverloaded(
        [](int i) { std::cout << "int\n";},
        [](float i) { std::cout << "float\n";}
    );


    o(1);
    o(1.1f);


    // int array[] = {1, 4, 3, 9, 7, 2};

    // //bool(*ptr)(int, int) = greater;

    // std::cout << findMax(array, sizeof(array)/sizeof(int), less) << std::endl;
    // std::cout << findMax(array, sizeof(array)/sizeof(int), Greater{}) << std::endl;


    std::vector<int> v = {1,2,3,4,5,6,7};
    // auto it = std::find_if(v.begin(), v.end(), GreaterThen{4});

    auto it = std::find_if(v.begin(), v.end(), std::bind(std::greater<int>{}, std::placeholders::_1, 4));


    if(it != v.end())
        std::cout << *it;


    std::bind1st
    return 0;
}