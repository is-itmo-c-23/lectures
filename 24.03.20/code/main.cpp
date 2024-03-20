#include <iostream>

#include <memory>


// 2й полупоток
// struct Foo {
//     int value;

//     Foo(int v)
//      : value(v)
//     {

//     }

//     Foo(const Foo& other)
//         : value(other.value)
//     {
//         throw std::runtime_error("KEKW");
//     }
// };

// class Boo {
// private:
//     std::unique_ptr<Foo> foo_;
//     int value_ = 0;
// public:

//     Boo(int value = 0)
//         : value_(value)
//     {}

//     Boo(int value, int foo_value)
//         : foo_(new Foo{foo_value})
//         , value_(value)
//     {}

//     ~Boo() {

//     }

//     Boo(const Boo& other)
//         : value_(other.value_)
//         , foo_(new Foo(*other.foo_))
//     {
//     }

//     void func() noexcept {

//     }

//     Boo& operator=(const Boo& other) {
//         if(this == &other)
//             return *this;

//         Boo tmp(other);

//         ///swap(*this, tmp);
//         *this = std::move(tmp);

//         return *this;
//     }

//     friend std::ostream& operator<< (std::ostream& stream, const Boo& value);
// private:
//     static void swap(Boo& lhs, Boo& rhs) {
//         std::swap(lhs.value_, rhs.value_);
//         std::swap(lhs.foo_, rhs.foo_);
//     }
// };


// void func() {
//     throw std::string{"abc"};
// }


// int main(int, char**){
//     try {
//         func();
//     }
//     catch(int i) {
//         std::cout << i << std::endl;
//     }
//     catch(const std::string& s) {
//         std::cout << s << std::endl;

//     }
// }



// 1й полупоток


struct Foo {
    int value;

    Foo(int v)
        : value(v)
    {}

    Foo(const Foo& other)
        : value(other.value)
    {
        throw std::runtime_error("KEKW");
    }
};


class Boo {
private:
    std::unique_ptr<Foo> foo_ = nullptr;
    int value_ = 0;

public:
    Boo(int value = 0)
        : value_(value)
    {}

    Boo(int value, int foo_value)
        : foo_(new Foo{foo_value})
        , value_(value)
    {}

    ~Boo() {

    }

    Boo(const Boo& other)
        : value_(other.value_)
        , foo_(new Foo(*other.foo_))
    {
    }

    void func() noexcept {

    }


    Boo& operator=(const Boo& other) {
        if(this == &other)
            return *this;

        Boo tmp(other);

        swap(*this, tmp);


        return *this;
    }

    private:
        static void swap(Boo& lhs, Boo& rhs) {
            std::swap(lhs.value_, rhs.value_);
            std::swap(lhs.foo_, rhs.foo_);
        }
};


Foo func() {
    throw std::string{"Some strange error"};
    return Foo{1};
}

int main () {
    try {
        func();
    } catch(int i) {
        std::cout << i << std::endl;
    }
    catch(const std::string& s) {

        std::cout << s << std::endl;
    }

    // Boo b{1,2};
    // Boo b2{1,2};

    // try {
    //     b2 = b;
    // }
    // catch (const std::runtime_error& e){
    //     std::cout << e.what() << std::endl;
    // }


    return 0;
}