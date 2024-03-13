#include <iostream>

#include <vector>
#include <array>
#include <iterator>
#include <fstream>

// 1й полупоток
// struct  Foo {
//     Foo(int f)
//         : field(f)
//     {}

//     Foo(const Foo&) = default;
//     Foo& operator=(const Foo&) = default;

//     Foo(Foo&&) = default;
//     Foo& operator=(Foo&&) = default;

//     int field;
// };


// std::ostream& operator<<(std::ostream& stream, const Foo& value) {
//     stream << value.field;

//     return stream;
// }


// template<typename Container>
// class MyBackInsertIterator {
// public:
//     using reference = Container::reference;
//     using const_reference = Container::const_reference;
//     using value_type = Container::value_type;

//     MyBackInsertIterator(Container& c)
//         : container_(c)
//     {
//     }

//     MyBackInsertIterator& operator++() {
//         return *this;
//     }

//     MyBackInsertIterator operator++(int) {
//         return *this;
//     }

//     MyBackInsertIterator& operator*() {
//         return *this;
//     }


//     MyBackInsertIterator& operator=(const_reference value) {
//         container_.push_back(value);


//         return *this;
//     }


// private:
//     Container& container_;
// };

// int main(int, char**){
//     std::array<Foo, 5> arr = {1, 2, 3, 4, 5};

//     std::vector<Foo> v;

//     // arr -> v

//     // for(int i : arr)
//     //     v.push_back(i);

//     //v.insert(v.end(), arr.begin(), arr.end());

//     std::copy(arr.begin(), arr.end(), MyBackInsertIterator(v));

//     for(const Foo& i : v)
//         std::cout << i << " ";

//     std::cout << std::endl;
// }






void func(std::array<int,5>& arr, std::vector<int>& v) {
    std::copy(arr.begin(), arr.end(), v.begin());
}



struct Foo {
    Foo(int f)
         : field(f)
    {}


    int field;
};

std::ostream& operator<<(std::ostream& stream, const Foo& value) {
    stream << value.field;
    return stream;
}


template<typename Container>
class SomeClass {
public:
    using value_type = Container::value_type;
    using const_reference = Container::const_reference;

    SomeClass(Container& c)
        : container_(c)
    {}

    SomeClass& operator=(const_reference value) {
        container_.push_back(value);

        return *this;
    }

private:
    Container& container_;
};


template<typename Container>
class MyBackInsertIterator {
public:
    using value_type = Container::value_type;
    using reference = Container::reference;
    using const_reference = Container::const_reference;

    MyBackInsertIterator(Container& container)
        : container_(container)
    {}

    MyBackInsertIterator& operator++() {
        return *this;
    }

    MyBackInsertIterator operator++(int) {
        return *this;
    }

    MyBackInsertIterator& operator=(const_reference value) {
        container_.push_back(value);
        return *this;
    }

    MyBackInsertIterator& operator*() {

        return *this;
    }

private:
    Container& container_;
};

// 2й полупоток
int main() {

    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    std::vector<int> v = { 1, 2, 3};


    // copy arr to v;
    // for(int i : arr)
    //     v.push_back(i);


   // std::copy(arr.begin(), arr.end(), MyBackInsertIterator(v));

    {
        std::ofstream out("out.txt");

        std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(out, " "));
    }
    {
        std::ifstream in("out.txt");

        std::copy(
            std::istream_iterator<int>(in),
            std::istream_iterator<int>(),
            MyBackInsertIterator(v)
        );
    }


    for(const Foo& i : v)
        std::cout << i << " ";

    std::cout << std::endl;

    return 0;
}


