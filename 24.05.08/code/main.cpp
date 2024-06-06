#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>


//1й полукоток
// namespace lecture {

// struct Foo {
//     int value = 1;
// };

// std::ostream& operator<<(std::ostream& stream, const Foo& foo) {
//     stream << "Foo(" << foo.value << ")";
//     return stream;
// }

// template<typename T>
// std::string to_string(T&& foo) {
//     std::stringstream ss;
//     ss << foo;
//     return ss.str();
// }

// // template<typename... TArgs>
// // std::vector<std::string> to_strings(const TArgs&... args) ;

// // std::vector<std::string> to_strings() {
// //     return {};
// // }

// // template<typename T, typename... TArgs>
// // std::vector<std::string> to_strings(const T& t, const TArgs&... args) {
// //     std::vector<std::string> result;
// //     result.emplace_back(to_string(t));

// //     auto strs = to_strings(args...);

// //     result.insert(result.end(), strs.begin(), strs.end());
// //     return result;
// // }

// template<typename... TArgs>
// std::vector<std::string> to_strings(const TArgs&... args) {
//     return {to_string(args)...};
// }


// template<typename... T>
// auto summ(const T&... args) {
//     //return (... - args);
//     return (1.0 / ... / args );
// }



// // template<typename T, typename U>
// // std::vector<std::string> to_strings(T&& t, U&& u) {
// //     std::vector<std::string> result;


// //     result.emplace_back(to_string(std::forward<T>(t)));
// //     result.emplace_back(to_string(std::forward<U>(u)));

// //     return result;
// //  }


// template<typename... TArgs>
// struct NaiveTuple;

// template<>
// struct NaiveTuple<> {

// };


// template<typename Head, typename... Tail>
// struct NaiveTuple<Head, Tail...> :  NaiveTuple<Tail...> {
//     using Base = NaiveTuple<Tail...>;

//     NaiveTuple(const Head& h, const Tail&... tail)
//         : head(h)
//         , Base(tail...)
//     {}

//     Head head;


//     const Base& base() const {
//         return static_cast<const Base&>(*this);
//     }
// };






// } // namespace lecture


// int main(int, char**){
//     using namespace lecture;

//     NaiveTuple<int, float, std::string> t {1, 1.0, "aaa"};
//     // std::cout << get<1>(t) << std::endl;




//     // std::cout << summ(10.0, 2.0) << std::endl;

//     // Foo f;

//     // for(std::string& s :  to_strings(f, 1, "aaa"))
//     //     std::cout << s << std::endl;
// }




// 2й полупоток



namespace lecture {
struct Foo {
    int value = 1;
};


std::ostream& operator<<(std::ostream& stream, const Foo& f) {
    stream << "Foo(" << f.value << ")";

    return stream;
}

template<typename T>
std::string to_string(const T& value) {
    std::stringstream ss;
    ss << value;

    return ss.str();
}

// template<typename T1, typename T2, typename T3>
// std::vector<std::string> to_strings(const T1& t1, const T2& t2, const T3& t3) {
//     return {to_string(t1), to_string(t2), to_string(t3)};
// }

// template<typename... TArgs>
// std::vector<std::string> to_strings(const TArgs&... args) ;


// template<>
// std::vector<std::string> to_strings<>() {
//     return {};
// }

// template<typename T, typename... TArgs>
// std::vector<std::string>  to_strings(const T& t, const TArgs&... args) {
//     std::vector<std::string> result;
//     result.emplace_back(to_string(t));

//     auto strs = to_strings(args...);

//     result.insert(result.end(), strs.begin(), strs.end());

//     return result;
// }


template<typename... TArgs>
std::vector<std::string> to_strings(const TArgs&... args) {
    return {to_string(args)...};
}


template<typename... TArgs>
auto summ(const TArgs&... args) {
    //return (args - ...);
    return ( args / ... / 2.0);
}



template<typename... TArgs>
struct  NaiveTuple;


template<>
struct NaiveTuple<> {

};


template<typename Head, typename... Tail>
struct NaiveTuple<Head, Tail...> : NaiveTuple<Tail...>{

    using Base = NaiveTuple<Tail...>;

    NaiveTuple(const Head& h, const Tail&... tail)
        : head(h)
        , Base(tail...)
    {}

    Head head;
    Base& base = static_cast<Base&>(*this);

};





template<size_t I, typename... TArgs>
auto get(NaiveTuple<TArgs...>& tuple) {
    return get<I-1>(tuple.base);
}


template<typename... TArgs>
auto get<0, TArgs...> (NaiveTuple<TArgs...>& tuple) {
    return tuple.head;
}


/*
    NaiveTuple<Foo, float, const char*>  foo, 1.0, "aaa"
    NaiveTuple<float, const char*>  1.0 "aaaa"
    NaiveTuple<const char*>   "aaaa"
    NaiveTuple<>

    foo
*/


} // namespace lecture

int main() {
    using namespace lecture;

    NaiveTuple<int, int, int> t {1, 2, 3};
    std::cout << sizeof(t) << std::endl;
    //std::cout << t.base.base.head << std::endl;

    //std::cout << summ(2, 5.0) << std::endl;
    // Foo f;


    // //printf("%s, %f, %s", 2, 1.0, "aaa");
    // for(const auto& s : to_strings(f, 1.0, "aaa"))
    //     std::cout << s << std::endl;

    return 0;
}