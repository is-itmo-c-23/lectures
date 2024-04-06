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


// class Foo {
// public:
//     Foo() = default;
//     Foo(int value)
//         : value_(value)
//     {}

//     void func() const {
//         std::cout << value_ << std::endl;
//     }

// private:
//     int value_;
// };




// template<typename F>
// class MyStdFunctionTwo;

// template<typename R, typename T>
// class MyStdFunctionTwo<R(T,T)> {
//     struct ICallable {
//         virtual R invoke(T a, T b) = 0;
//         virtual ~ICallable() = default;
//     };

//     template<typename TCallable>
//     class TCallableImpl : public ICallable {
//     public:
//         TCallableImpl(const TCallable& callable)
//              : callable_(callable)
//         {}

//         R invoke(T a, T b) {
//             return callable_(a, b);
//         }

//     private:
//         TCallable callable_;
//     };

// public:

//     template<typename TCallable>
//     MyStdFunctionTwo(TCallable callable)
//         : callable_(new TCallableImpl<TCallable>(callable))
//     {}


//     R operator()(T a, T b) {
//         return callable_->invoke(a, b);
//     }

// private:
//     std::unique_ptr<ICallable> callable_;

// };



// #include <ranges>
// int main(int, char**){

//     MyStdFunctionTwo<bool(int, int)> f = Grater{};
//     MyStdFunctionTwo<bool(int, int)> f2 = greater;
//     MyStdFunctionTwo<bool(int, int)> f3 = [](int a, int b){return a > b;};

//     std::cout << f(1,2) << std::endl;
//     std::cout << f2(1,2) << std::endl;
//     std::cout << f3(1,2) << std::endl;


//     std::ranges::views::take



//     //std::function<int(const Foo&, int)> f4 = &Foo::incr;

//     //std::function<void(const Foo&)> f = &Foo::func;

//     // for(int i = 0; i < 4; ++i) {
//     //     Foo foo{i};
//     //     f(foo);
//     // }

//     // auto factorial = [] (size_t n) {
//     //     return  n * factorial(n-1);
//     // };

//     // std::cout << factorial(5);


// //     std::vector<int> v = {1,2,3,4,5,6,7};

// //     auto it = std::find_if(v.begin(), v.end(), GreaterThen{4});
// //     //auto it = std::find_if(v.begin(), v.end(), std::greater<int>{});

// // //    auto it = std::find_if(v.begin(), v.end(), [](int value) -> bool { return value > 4;});


// //     std::bind(std::greater<int>{}, std::placeholders::_1, 4);






//     // if(it != v.end())
//     //     std::cout << *it;


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




class Foo {
public:
    Foo(int value)
        : value_(value)
    {}

    int func() {
        return value_;
    }

private:
    int value_;
};



template<typename TFunc>
class MyStdFunctionTwo;


template<typename R, typename Arg>
class MyStdFunctionTwo<R(Arg, Arg)> {

    struct ICallable  {
        virtual R invoke(Arg a, Arg b) = 0;
        virtual ~ICallable() = default;
    };


    template<typename TCallable>
    class TCallableImpl : public ICallable {
    public:
        TCallableImpl(const TCallable& callable)
            : callable_(callable)
        {}

        R invoke(Arg a, Arg b) override {
            return callable_(a, b);
        }

    private:
        TCallable callable_;
    };

public:
    template<typename TCallable>
    MyStdFunctionTwo(TCallable callable)
        : callable_(new TCallableImpl<TCallable>(callable))
    {}

    R operator()(Arg a, Arg b)  {
        return callable_->invoke(a, b);
    }

private:
    std::unique_ptr<ICallable> callable_;


};



template<typename T>
class ObjStore {
public:
    ObjStore(const T& obj)
        : obj_(obj)
    {}

private:
    T obj_;
};


// {
// public:
//     MyStdFunctionTwo(TFunc* func)
//         : func_(func)
//     {}

//     template<typename T>
//     auto operator()(T a, T b) {
//         return func_(a, b);
//     }
// private:
//     TFunc* func_;
// };

int main() {

   MyStdFunctionTwo<bool(int,int)> f1 = Greater{};
   MyStdFunctionTwo<bool(int,int)> f2 = greater;
   MyStdFunctionTwo<bool(int,int)> f3 = [](int a, int b) { return a > b;};

    std::cout << f1(1,2) << std::endl;
    std::cout << f2(1,2) << std::endl;
    std::cout << f3(1,2) << std::endl;


    // std::function<int(Foo*)> f = &Foo::func;

    // for(int i = 0; i < 4; ++i) {
    //     Foo foo{i};
    //     std::cout << f(&foo) << std::endl;
    // }


    // auto realFactorial = [](size_t n) {

    //     auto factorial = [](size_t n, const auto& factorialImpl) -> int {
    //       if(n < 2)
    //             return 1;
    //         return n * factorialImpl(n-1, factorialImpl);
    //     };

    //     return factorial(n, factorial);
    // };

    // std::cout << realFactorial(5);

    // auto o = MakeOverloaded(
    //     [](int i) { std::cout << "int\n";},
    //     [](float i) { std::cout << "float\n";}
    // );


    // o(1);
    // o(1.1f);


    // // int array[] = {1, 4, 3, 9, 7, 2};

    // // //bool(*ptr)(int, int) = greater;

    // // std::cout << findMax(array, sizeof(array)/sizeof(int), less) << std::endl;
    // // std::cout << findMax(array, sizeof(array)/sizeof(int), Greater{}) << std::endl;


    // std::vector<int> v = {1,2,3,4,5,6,7};
    // // auto it = std::find_if(v.begin(), v.end(), GreaterThen{4});

    // auto it = std::find_if(v.begin(), v.end(), std::bind(std::greater<int>{}, std::placeholders::_1, 4));


    // if(it != v.end())
    //     std::cout << *it;




    return 0;
}