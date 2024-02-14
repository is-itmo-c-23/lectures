#include <iostream>
#include <vector>
#include <string>

// 1й полупоток
// // Full
// // template <class T>
// // struct Boo {
// //     void foo() {
// //         std::cout << "foo" << std::endl;
// //     }

// //     void func() {}
// // };

// // template <>
// // struct Boo<int> {
// //     void foo() {
// //         std::cout << "foo(int)" << std::endl;
// //     }
// // };


// // template <class T>
// // struct is_float {
// //     static bool value() { return false; }
// // };

// // template <>
// // struct is_float <float> {
// //     static bool value() { return true; }
// // };




// // template <class T>
// // static bool is_float_v = is_float <T>::value();




// // Partial
// template <class T, class U>
// struct Boo {
//     void foo() {
//         std::cout << "A" << std::endl;
//     }

//     void func () {};
// };

// template <class U>
// struct Boo<int, U> {
//     void foo() {
//          std::cout << "B" << std::endl;
//     }
// };


// template <class U>
// struct Boo<U, float> {
//     void foo() {
//          std::cout << "D" << std::endl;
//     }
// };



// template <>
// struct Boo<int, int> {
//     void foo() {
//         std::cout << "C" << std::endl;
//     }
// };


// template <>
// struct Boo<int, float> {
//     void foo() {
//         std::cout << "E" << std::endl;
//     }
// };


// // template<unsigned N>
// // struct factorial {
// //     enum {value = N * factorial<N-1>::value };
// // };

// // template <>
// // struct factorial<0> {
// //     enum {value = 1};
// // };

// // struct Foo {
// //     enum { value = 2024 };

// // };


// // struct factorial5 {
// //     enum {value = 120 };
// // };

// // struct factorial4 {
// //     enum {value = 24 };
// // };


// // struct factorial3 {
// //     enum {value = 6 };
// // };

// // struct factorial2 {
// //     enum {value = 2 };
// // };

// // struct factorial1 {
// //     enum {value = 1 };
// // };

// // template<typename T>
// // void func(const T& ){
// //     std::cout << is_float_v<T> << std::endl;
// // }

// // template <class T>
// // void swap(T& a, T& b) {
// //     T tmp = a;
// //     a = b;
// //     b = tmp;
// // }

// // struct SomeStruct {};


// // template <>
// // void swap<SomeStruct>(SomeStruct& a, SomeStruct& b) {
// //     std::cout << "swap for SomeStruct with template" << std::endl;
// // }


// // template<typename T>
// // void swap(std::vector<T>& a, std::vector<T>& b) {
// //     a.swap(b);
// // }

// struct Boo {
//     Boo() { std::cout << "Boo()\n";}
//     ~Boo() {std::cout << "~Boo()\n";}

//     void foo() {}
// };

// template<class T, class Deleter>
// class auto_ptr {
// public:
//     auto_ptr(T* ptr = nullptr)
//         :ptr_(ptr)
//     {}

//     auto_ptr(auto_ptr& other)
//         : ptr_(other.ptr_)

//     {
//         other.ptr_ = nullptr;
//     }

//     ~auto_ptr() {
//         Delete
//         if(ptr_)
//             delete ptr_;
//     }

//     T* operator->() {
//         return ptr_;
//     }

//     T& operator*() {
//         return *ptr_;
//     }
// private:
//     T* ptr_;
// };


// void func() {
//     auto_ptr<Boo> b{new Boo()};
//     b->foo();
//     return ;

//     auto_ptr<Boo> b2 = b;

//     //delete b;
// }

// int main(int, char**){

//     func();
//     // BooInt b;
//     // b.foo();

//     // std::vector<Boo<float>> bf;
//     // std::vector<Boo<int>> bf;
//     // std::vector<BooInt> bf;

//     // func(1);
//     // func(1.1);
//     // func(1.1f);

//     // std::vector<int> a, b;
//     // swap(a,b);


//     // Boo<int, float> b;
//     // b.foo();

// }


// 2й полупоток

// Full
// template <class T>
// struct Boo {
//     void foo() {
//         std::cout << "foo" << std::endl;
//     }

//     void func() {}
// };

// template <>
// struct Boo<int> {
//     void foo() {
//         std::cout << "foo(int)" << std::endl;
//     }
// };



// templeta<typename T>
// void func(const Boo<T>&) {

// }

// template<typename T>
// struct S {
//     Boo<T> b;
// }





// // Partial
// template <class T, class U>
// struct Boo {
//     void foo() {
//         std::cout << "A" << std::endl;
//     }

//     void func () {};
// };




// template <>
// struct Boo<int, float> {
//     void foo() {
//         std::cout << "E" << std::endl;
//     }
// };


// template <class T>
// struct is_float {
//     static bool value() { return false; }
// };

// template <>
// struct is_float <float> {
//     static bool value() { return true; }
// };





// template <class T>
// static bool is_float_v = is_float <T>::value();




// template<typename T>
// struct is_our_type {
//     static constexpr bool value() { return false; }
// };


// template<>
// struct is_our_type<float> {
//     static constexpr bool  value() { return true; }
// };


// template<>
// struct is_our_type<bool> {
//     static bool constexpr value() { return true; }
// };


// template<>
// struct is_our_type<int> {
//     static constexpr bool value() { return true; }
// };


// template<typename T>
// static constexpr bool is_our_type_v =  is_our_type<T>::value();



// template<typename T>
// void func(const T&) {
//     std::cout << is_float_v<T> << std::endl;
// }

// template <class T>
// void my_swap(T& a, T& b) {
//     T tmp = a;
//     a = b;
//     b = tmp;
// }

// struct SomeStruct {

// };


// template<typename T>
// void my_swap(std::vector<T>& a, std::vector<T>& b){
//     a.swap(b);
// }


// template<>
// void my_swap(SomeStruct& a, SomeStruct& b) {
//     std::cout << "My best swap for SomeStruct" << std::endl;
// }



// void my_swap(SomeStruct& a, SomeStruct& b) {
//     std::cout << "My best swap for SomeStruct without template" << std::endl;
// }




// template <class T, class U>
// struct Boo {
//     void foo() {
//          std::cout << "A" << std::endl;
//     }

//     void func() {}
// };




// template <class U>
// struct Boo<int, U> {
//     void foo() {
//          std::cout << "B" << std::endl;
//     }
// };



// template <class U>
// struct Boo<U, float> {
//     void foo() {
//          std::cout << "D" << std::endl;
//     }
// };


// template <>
// struct Boo<int, int> {
//     void foo() {
//         std::cout << "C" << std::endl;
//     }
// };

// template <>
// struct Boo<int, float> {};


// // int, bool, float
// template<typename T>
// struct Foo
// {
//     static_assert(is_our_type_v<T> );
// };


struct Boo {
    Boo() { std::cout << "Boo()\n";}
    ~Boo() {std::cout << "~Boo()\n";}

    void func() {}
};

template<class T>
class auto_ptr {
public:
    auto_ptr(T* ptr = nullptr)
        :ptr_(ptr)
    {}

    ~auto_ptr() {
        delete ptr_;
    }

    auto_ptr(auto_ptr& other)
         : ptr_(other.ptr_)
    {
    other.ptr_ = nullptr;
    }

    T* operator->() {
        return ptr_;
    }

    T& operator*() {
        return *ptr_;
    }

private:
    T* ptr_;
};


void func() {
    auto_ptr<Boo> b {new Boo()};
    b->func();

    auto_ptr<Boo> b2 = b;
    return;
}


int main() {
    func();

    // Boo<int, float> b;

    // b.foo();

    // func(1);
    // func(1.1);
    // func(1.1f);


    // std::vector<int> a, b;


    // my_swap(a, b);

    return 0;
}