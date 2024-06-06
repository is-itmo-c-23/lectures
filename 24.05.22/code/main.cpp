#include <iostream>
#include <cassert>

// 1й поток
// constexpr unsigned factorial(unsigned n) {
//     if(n == 0)
//         return 1;

//     return factorial(n-1);
// }


// // template <typename T>
// // void print(T value) {
// //     std::cout << "Value = " << value << std::endl;
// // }

// // // template <>
// // // void print<int>(int value) {
// // //     std::cout << "Int value = " << value << std::endl;
// // // }

// // template <>
// // void print(int* value) {
// //     std::cout << "Int pointer value = " << *value << std::endl;
// // }


// // template <typename T>
// // void print(T* value) {
// //     std::cout << "Pointer Value = " << *value << std::endl;
// // }


// template<typename T, typename V>
// struct is_same {
//     static constexpr bool value = false;
// };


// template<typename T>
// struct is_same<T, T> {
//     static constexpr bool value = true;
// };




// // struct Boo {
// //     Boo() {
// //         std::cout << "Boo()\n";
// //     }

// //     Boo(const Boo&) {
// //         std::cout << "Boo(const Boo&)\n";
// //     }

// //     Boo(Boo&&) {
// //         std::cout << "Boo(Boo&&)\n";
// //     }

// //     ~Boo() {
// //         std::cout << "~Boo\n";
// //     }

// // };


// template<typename... Args>
// int sum(Args... args) {
//     return (args + ...);
// }


// template<int... args>
// struct Sum {
//     constexpr static int value = (args + ...);
// };

// template<typename T>
// struct identity {
//     using type = T;
// };



// bool is_equal(int a, int b) {
//     return  a == b;
// }


// template <typename T, T Value>
// struct integral_constant {
//     static constexpr T value = Value;
//     using value_type = T;
//     using type = integral_constant ;

//     constexpr operator value_type () const noexcept { return value; }
//     constexpr value_type operator()() const noexcept { return value; }
// };








// // template < bool B >
// // using bool_constant = integral_constant <bool, B>;

// // using true_type = integral_constant <bool, true>;
// // using false_type = integral_constant <bool, false>;





// template<typename T>
// struct is_pointer : std::false_type {};

// template<typename T>
// struct is_pointer<T*> : std::true_type {};

// // template<typename T>
// // struct is_pointer<T* const> : std::true_type {};


// // template<T>
// // struct remove_const {
// //     using type = T;
// // };


// // template<T>
// // struct remove_const<const T> {
// //     using type = T;
// // };




// // 1
// // template<typename T>
// // void print(const T& value) {
// //     if constexpr (std::is_pointer_v<T>) {
// //         std::cout << *value << std::endl;
// //     } else {
// //         std::cout << value << std::endl;
// //     }
// // }






// template<typename T, bool IsPointer>
// struct Print;





// // template<typename T>
// // struct Print<T, true> {
// //     static void print(const T& value) {
// //         std::cout << *value << std::endl;
// //     }
// // };

// // template<typename T>
// // struct Print<T, false> {
// //     static void print(const T& value) {
// //         std::cout << value << std::endl;
// //     }
// // };

// // }


// // template<typename T>
// // void print(const T& value) {
// //     details::Print<T, std::is_pointer_v<T>>::print(value);
// // }


// // template<typename T>
// // void print(std::true_type x, const T& value) {
// //     std::cout << *value << std::endl;
// // }


// // template<typename T>
// // void print(std::false_type x, const T& value) {
// //     std::cout << value << std::endl;
// // }


// // template<typename T>
// // void print(const T& value) {
// //     print(typename std::is_pointer<T>::type{}, value);
// // }

// struct Boo {
//     //int value;
// };


// template<typename T>
// void foo(int T::*) {
//     std::cout << "void foo(int T::*)\n";
// }


// template<typename T>
// void foo(...) {
//     std::cout << "void foo(...)\n";
// }

// template <typename T>
// std::true_type  can_have_member_ptr(int T::*);

// template <typename T>
// std::false_type can_have_member_ptr(...);


// template <bool, class T = void>
// struct enable_if {};

// template <class T>
// struct enable_if<true, T> {
//     using type = T;
// };

// template <bool B, class T = void>
// using enable_if_t = typename enable_if<B, T>::type;


// template <typename T>
// void print(const T& value, std::enable_if_t <std::is_pointer_v <T>, void*> = nullptr) {
//     std::cout << *value << std::endl;
// }

// template <typename T>
// void print(const T& value, std::enable_if_t <!std::is_pointer_v <T>, void*> = nullptr) {
//     std::cout << value << std::endl;
// }


// int main(int, char**){

//     int i = 1;
//     print(i);

//     print(&i);
//     // enable_if_t<std::is_pointer_v<int*>, int> i = 1;
//     // enable_if_t<std::is_pointer_v<int>, int> i = 1;

//     // static_assert(decltype(can_have_member_ptr<Boo>(nullptr)){});
//     // static_assert(!decltype(can_have_member_ptr<int>(nullptr)){});

//     using IntBooMemberPtr = int Boo::*;

//    // foo<Boo>(nullptr);
//    // foo<int>(nullptr);


//     // int i = 1;
//     // print(i);
//     // print(&i);
//     // Print<int, std::is_pointer_v<int>>{}(i);
//     // Print<int*, std::is_pointer_v<int*>>{}(&i);

//     // static_assert(Factorial<5>::value == 120);

//     //static_assert(is_pointer<int * const>::value);
//     // assert(
//     //     is_equal(identity(100500), 100500))
//     // )
//     // static_assert(
//     //     is_same<identity<Boo>::type, Boo>::value
//     // );
//     //static_assert(Sum<1,2,3,4,5>::value == 16);
//     //assert(sum(1,2,3,4,5) == 15);

//     // Boo b1;
//     // Boo b  = identity(std::move(b1));

//     // assert(identity(100500) == 100500);
//     // static_assert(value_identity<100500>::value == 100500);

//     //static_assert(!is_same<int,float>::value);

//     // int i = 1;
//     // print(i);
//     // print(&i);
//     // print(1.2);
//     // print(2);

//     // constexpr  int i = 5;
//     // constexpr  int x = factorial(i);
// }


// 2й полупоток


struct Boo {
    Boo() {
        std::cout << "Boo()\n";
    }

    Boo(const Boo&) {
         std::cout << "Boo(const Boo&)\n";
    }


    Boo(Boo&&) {
         std::cout << "Boo(Boo&&)\n";
    }

    ~Boo() {
         std::cout << "~Boo()\n";
    }
};

template<unsigned N>
struct Factorial {
    enum {
        Value = N * Factorial<N-1>::Value
    };
};

template<>
struct Factorial<0> {
    enum {
        Value = 1
    };
};



unsigned factorial(unsigned n) {
    if(n == 0)
        return 1;

    return n * factorial(n-1);
}




template<typename T, typename U>
struct is_same {
    static constexpr bool value = false;
};


template<typename T>
struct is_same<T,T> {
    static constexpr bool value = true;
};


template<typename T, typename U>
constexpr bool is_same_v = is_same<T,U>::value;


bool is_equal(int a, int b) {
    return a == b;
}

template<typename T>
T&& identity(T&& value) {
    return std::forward<T>(value);
}


template<auto Value>
struct value_identity {
    static constexpr auto value = Value;
};


template<auto Value>
constexpr auto value_identity_v = value_identity<Value>::value;


template<typename T>
struct type_identity {
    using type = T;
};

template<typename T>
using type_identity_t = typename type_identity<T>::type;





template <typename T, T Value>
struct integral_constant {
    static constexpr T value = Value;
    using value_type = T;
    using type = integral_constant ;

    constexpr operator value_type () const noexcept { return value; }
    constexpr value_type operator()() const noexcept { return value; }
};







template < bool B >
using bool_constant = integral_constant <bool, B>;


using true_type = integral_constant <bool, true>;
using false_type = integral_constant <bool, false>;



template<typename T>
struct is_pointer : std::false_type {};

template<typename T>
struct is_pointer<T*> : std::true_type {};

template<typename T>
struct is_pointer<T* const> : std::true_type {};


template<typename T>
struct remove_const {
    using type = T;
};


template<typename T>
struct remove_const<const T> {
    using type = T;
};


// 1
// template<typename T, bool IsPointer>
// struct Print {
//     static void print(const T& value) {
//         std::cout << value << std::endl;
//     };
// };

// template<typename T>
// struct Print<T, true> {
//     static void print(const T& value) {
//         std::cout << *value << std::endl;
//     };
// };



// template<typename T>
// void print(const T& value) {
//     Print<T, std::is_pointer_v<T>>::print(value);
// }

// 2
// template<typename T>
// void print(std::true_type, const T& value) {
//     std::cout << *value << std::endl;
// }

// template<typename T>
// void print(std::false_type, const T& value) {
//     std::cout << value << std::endl;
// }

// template<typename T>
// void print(const T& value) {
//     print(typename std::is_pointer<T>::type{}, value);

// }



// 3
// template<typename T>
// void print(const T& value) {
//     if constexpr (std::is_pointer_v<T>) {
//         std::cout << *value << std::endl;
//     } else {
//         std::cout << value << std::endl;
//     }
// }



// void func(int i) {
//     std::cout << "int\n";
// }

// void func(...) {
//     std::cout << "...\n";
// }


struct Foo {};


template<typename T>
void func(int T::*) {
    std::cout << "void func(int T::* = nullptr)\n";
}

template<typename T>
void func(...) {
    std::cout << "void func()\n";
}

template <typename T>
std::true_type can_have_member_ptr(int T::*);

template <typename T>
std::false_type can_have_member_ptr(...);



template <bool, class T = void>
struct enable_if {};

template <class T>
struct enable_if<true, T> {
    using type = T;
};

template <bool B, class T = void>
using enable_if_t = typename enable_if<B, T>::type;


// 4
// template <typename T>
// void print(const T& value, std::enable_if_t <std::is_pointer_v <T>, void*> = nullptr) {
//     std::cout << *value << std::endl;
// }

// template <typename T>
// void print(const T& value, std::enable_if_t <!std::is_pointer_v <T>, void*> = nullptr) {
//     std::cout << value << std::endl;
// }

// 5
template <typename T>
requires std::is_pointer_v<T>
void print(const T& value) {
    std::cout << *value << std::endl;
}

template <typename T>
void print(const T& value) {
    std::cout << value << std::endl;
}

int main() {

    int i = 1;
    print(i);
    print(&i);
    // enable_if_t<std::is_pointer_v<int*>, void>* p = nullptr;


    // static_assert(decltype(can_have_member_ptr<Boo>(nullptr)){});
    // static_assert(!decltype(can_have_member_ptr<int>(nullptr)){});


    // func<Foo>(nullptr);
    // func<int>(nullptr);


    //static_assert(is_pointer<int* volatile const >{});
   // Boo b52;
    // assert(identity(100500) == 100500);
    // static_assert(value_identity_v<100500> == 100500);

    // static_assert(is_same_v<type_identity_t<Boo>, Boo>);


    // assert(is_equal(1,1));

    // static_assert(is_same<float, int>::value);


    // int i = 1;
    // print(i);
    // print(&i);
}

