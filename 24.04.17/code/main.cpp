#include <iostream>




// 2й полупоток


struct Foo {
    Foo() {
        std::cout << "Foo()\n";
    }
    Foo(int i) {}

    Foo(const Foo&) {
        std::cout << "Foo(const Foo&)\n";
    }

    Foo(Foo&&) {
        std::cout << "Foo(Foo&&)\n";
    }
};



void func(const Foo& v) {
}


void f(Foo* f) {

}

void foo(Foo& ) {
    std::cout << "void foo(Foo& ) \n";
}

void foo(const Foo& ) {
    std::cout << "void foo(const Foo& ) \n";
}

void foo(Foo&& ) {
    std::cout << "void foo(Foo&& ) \n";
}



class CArray {
public:
    CArray() = default;

    explicit CArray(size_t size)
        : size_(size)
        , data_(new int8_t[size])
    {
        std::cout << "CArray()\n";
    }

    ~CArray() {
        delete[] data_;
        std::cout << "~CArray()\n";
    }


    CArray(const CArray& array)
        : size_(array.size_)
        , data_(new int8_t[array.size_])
    {
        std::copy(array.data_, array.data_ + array.size_, data_);
        std::cout << "CArray(const CArray& array)\n";
    }

    CArray(CArray&& array) noexcept
        : size_(std::exchange( array.size_, 0))
        , data_(std::exchange( array.data_, nullptr))
    {
        std::cout << "CArray(CArray&&)\n";
    }

    CArray& operator=(const CArray& array)  {
        std::cout << "operator=(const CArray& array)\n";
        if(this == &array)
            return *this;


        CArray tmp(array);
        swap(tmp);

        return *this;
    }

    CArray& operator=(CArray&& array) {
        std::cout << "operator=(CArray&& array)\n";
        std::swap(size_, array.size_);
        std::swap(data_, array.data_);

        return *this;
    }

    // CArray& operator=(CArray array) {
    //     std::cout << "operator=(CArray array)\n";
    //     swap(array);
    //     return *this;
    // }

protected:
    void swap(CArray& array) {
        std::swap(array.size_, size_);
        std::swap(array.data_, data_);
    };

private:
    int8_t* data_ = nullptr;
    size_t size_ = 0;
};


CArray createArray() {
    return CArray{2};
}


template<class T>
void my_swap(T& x, T& y) {
    T tmp = std::move(x);
    x = std::move(y);
    y = std::move(tmp);
}



template<typename T, typename Arg>
std::unique_ptr<T> my_make_unique(Arg&& arg) {
    return std::unique_ptr<T>(new T(std::forward<Arg>(arg)));
}


// Foo& forward(Foo& arg) {
//     return static_cast<Foo&>(__t);
// }

// std::unique_ptr<Foo> my_make_unique(Foo& arg) {
//     return std::unique_ptr<T>(new T(std::forward<Foo&>(arg)));
// }

// Foo&& forward(Foo&& arg) {
//     return static_cast<Foo&&>(__t);
// }


// std::unique_ptr<Foo> my_make_unique(Foo&& arg) {
//     return std::unique_ptr<T>(new T(std::forward<Foo&&>(arg));
// }



// template <class _Tp>
// _LIBCPP_NODISCARD_EXT inline _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR _Tp&&
// forward(_LIBCPP_LIFETIMEBOUND __libcpp_remove_reference_t<_Tp>& __t) _NOEXCEPT {
//   return static_cast<_Tp&&>(__t);
// }

// template <class _Tp>
// _LIBCPP_NODISCARD_EXT inline _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR _Tp&&
// forward(_LIBCPP_LIFETIMEBOUND __libcpp_remove_reference_t<_Tp>&& __t) _NOEXCEPT {
//   static_assert(!is_lvalue_reference<_Tp>::value, "cannot forward an rvalue as an lvalue");
//   return static_cast<_Tp&&>(__t);
// }


struct Boo {

};

void boo(Boo&) {
    std::cout << "boo(Boo&)\n";
}

void boo(const Boo&) {
    std::cout << "boo(const Boo&)\n";
}

void boo(Boo&&) {
    std::cout << "boo(Boo&&)\n";
}

void boo(const Boo&&) {
    std::cout << "boo(const Boo&&)\n";
}

template<typename T>
void boo(T&&) {
    std::cout << "template<typename T> void boo(T&&))\n";
}

Foo rvo() {
    return Foo();
}

Foo nrvo() {
    Foo result;
    return result;
}

Foo createFoo(int i) {
    Foo odd;
    Foo even;
    return i % 2 == 0 ? odd : even;
}


int main () {
    Foo f = createFoo(1);

//    boo(Boo{});

    // Foo f;
    // auto p1 = my_make_unique<Foo>(f)
    // ;
    // auto p2 = my_make_unique<Foo>(Foo{});

//     CArray arr{10};
//     CArray arr2{5};
//    // arr = arr2;

//     //arr = std::move(arr2);
//     my_swap(arr, arr2);

    // // arr = CArray{5};
    // arr = createArray
    // ();



    // Foo f;
    // const Foo cf;
    // Foo&& rvf = Foo{};


    // foo(f);
    // foo(cf);
    // foo(Foo{});
    // foo(rvf);

    // Foo f;
    // Foo f2;

    // &f + &f2;

    // f(&f);

    // func(Foo{});
    // func(2);

    // int i;
    // i = 2024; // i - lvalue , 2024 - rvalue

    // 2024 = i;


    // int arr[10];
    // arr[1] = i;


}










// 1й полупоток
// // struct Foo
// // {
// //     /* data */
// // };


// // void foo(Foo& ) {
// //     std::cout << "void foo(Foo& ) \n";
// // }

// // void foo(const Foo& ) {
// //     std::cout << "void foo(const Foo& ) \n";
// // }

// // void foo(Foo&& ) {
// //     std::cout << "void foo(Foo&& ) \n";
// // }




// class CArray {
// public:
//     CArray() = default;

//     explicit CArray(size_t size)
//         : size_(size)
//         , data_(new int8_t[size])
//     {
//         std::cout << "CArray(size_t size)\n";
//     }

//     ~CArray() {
//         delete[] data_;
//         std::cout << "~CArray()\n";

//     }


//     CArray(const CArray& array)
//         : size_(array.size_)
//         , data_(new int8_t[array.size_])
//     {
//         std::copy(array.data_, array.data_ + array.size_, data_);


//         std::cout << "CArray(const CArray& array)\n";
//     }

//     CArray( CArray&& array) noexcept
//         : size_(std::exchange( array.size_, 0))
//         , data_(std::exchange( array.data_, nullptr))
//     {
//         std::cout << "CArray(CArray&& array)\n";
//     }

//     // CArray& operator=(const CArray& array)  {
//     //     std::cout << "operator=(const CArray& array)\n";
//     //     if(this == &array)
//     //         return *this;

//     //     CArray tmp(array);
//     //     swap(tmp);

//     //     return *this;
//     // }

//     // CArray& operator=(CArray&& array) {
//     //     std::cout << "operator=(CArray&& array)\n";

//     //     std::swap(size_, array.size_);
//     //     std::swap(data_, array.data_);

//     //     return *this;
//     // }

//     CArray& operator=(CArray array) {
//         std::cout << "operator=(CArray array)\n";
//         swap(array);
//         return *this;
//     }

// protected:
//     void swap(CArray& array) {
//         std::swap(array.size_, size_);
//         std::swap(array.data_, data_);
//     };

// private:
//     int8_t* data_ = nullptr;
//     size_t size_ = 0;
// };


// CArray createArray() {
//     return CArray{2};
// }


// // int main(int, char**){
// //     CArray arr1{4};
// //     CArray arr2{5};


// //     arr2 = arr1;

// //     // Foo f;
// //     // const Foo cf;
// //     // Foo&& rvf = Foo{};


// //     // foo(f);
// //     // foo(cf);
// //     // foo(Foo{});
// //     // foo(rvf); // !!!

// //     return 0;
// // }



// template<typename T, typename Arg>
// std::unique_ptr<T> my_make_unique(Arg&& arg) {
//     return std::unique_ptr<T>(new T(std::forward(arg)));
// }


// // template< typename T >
// // T&& forward(std::remove_reference_t<T>& t ) noexcept {
// //     return static_cast<T&&>( t );
// // }

// // template <class T>
// // typename remove_reference<_Tp>::type&&  move(T&& t) _NOEXCEPT {
// //     typedef typename remove_reference<_Tp>::type _Up;
// //     return static_cast<_Up&&>(__t);
// // }



// // Foo& forward(Foo& t ) noexcept {
// //     return static_cast<Arg&>( t );
// // }


// // std::unique_ptr<T> my_make_unique(Foo& arg) {
// //     return std::unique_ptr<T>(new T(std::forward(arg)));
// // }


// // Foo&& forward(Foo&& t ) noexcept {
// //     return static_cast<Arg&&>( t );
// // }


// // std::unique_ptr<T> my_make_unique(Foo&& arg) {
// //     return std::unique_ptr<T>(new T(std::forward(arg)));
// // }


// // struct Boo {

// // };

// // void boo(Boo&) {
// //     std::cout << "void boo(Boo&)\n";
// // }

// // void boo(const Boo&) {
// //     std::cout << "void boo(const Boo&\n";
// // }

// // void boo(Boo&&) {
// //     std::cout << "void boo(Boo&&)\n";
// // }

// // void boo(const Boo&&) {
// //     std::cout << "void boo(const Boo&&)\n";
// // }

// // template<typename T>
// // void boo(T&&) {
// //     std::cout << "template<typename T> void boo(T&&)\n";
// // }


// // int main () {
// //     Boo b;
// //     boo(std::move(b));

// //     // std::forward(Foo{});
// //     // Foo f{};
// //     // std::forward(f);
// //     // my_make_unique<Foo>(f);
// //     // my_make_unique<Foo>(Foo{});
// // }

// struct Foo {
//     Foo() {
//         std::cout << "Foo()\n";
//     }
//     Foo(const Foo&) {
//         std::cout << "Foo(const Foo&)\n";
//     }
//     Foo(Foo&&) {
//         std::cout << "Foo(Foo&&)\n";
//     }
// };


// Foo rvo() {
//     return Foo();
// }

// Foo nrvo() {
//     Foo result;
//     return result;
// }
// Foo createFoo(int i) {
//     Foo odd;
//     Foo even;
//     return i % 2 == 0 ? odd : even;
// }



// int main() {
//     Foo f = createFoo(1);
// }