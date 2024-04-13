#include <iostream>
#include <vector>

// 1й полупоток
// // struct Foo {
// //     int i = 64;
// // };

// // struct Boo {
// //     std::string str = "abc";
// // };

// // void func(Foo* b) {
// //     std::cout << b->i << std::endl;
// // }



// struct Foo {
//     Foo(float f) {};
// };

// struct Boo {
//     Boo(const std::string&) {}

//     operator int() {
//         return 2;
//     }
// };




// struct Base {
//     int i = 1;
//     virtual ~Base() {};
// };

// struct Derived : public Base {
//     int j = 2;
//     void func() {
//         std::cout << j << std:: endl;
//     }
// };



// int main(int, char**){
//     Base b{};
//     Derived& d = dynamic_cast<Derived&>(b);

//     //std::cout << d << std:: endl;
//     d.func();
//     return 0;



//     return 0;



//     void* t = new Derived();
//     static_cast<Derived*>(t)->func();




//     // Boo b("12345");
//     // Foo f = static_cast<Foo>(b);

//     // int i = 0;
//     // const int* cpi = &i;


//     // int* pi = const_cast<int*>(cpi);
//     // *pi = 100500;


//     // std::cout << i << std::endl;




//     // char* str = "Hello world!";
//     // const char* s = const_cast<const char*>(str);
//     // char* s2 = const_cast<char*>(s);
//     // s2[0] = 'A'; // Undefined behaviour !!

//     // std::cout << str << std::endl;

//     // // Boo b;
//     // Foo f;

//     // func((Foo*)&b);
//     //func(b);

//     // int i = 1;
//     // int* pi = &i;
//     // float* pd = (float*)pi;

//     // std::cout << *pd << std::endl;
// }


// struct  Foo {
//     int i = 84;
// };


// struct  Boo {
//     std::string str = "abc";
// };


// void func(Foo* f) {
//     std::cout << f->i << std::endl;
// }


// struct Foo {
//     Foo(float f) {};
// };


// struct Boo {
//     Boo(const std::string&) {}

//     operator int() {
//         return 2;
//     }
// };


struct Base {
    int i = 1;
    void func() {
        std::cout << i << std::endl;
    }

    virtual ~Base() {}
};

struct Derived : public Base {
    int j = 2;
    void func() {
        std::cout << j << std::endl;
    }
};

template<typename T>
struct Counter {
    static int created;
    Counter() {
        ++created;
    }
    Counter(const Counter&) {
        ++created;
    }
};


template<typename T> int Counter<T>::created = 0;

class Boo : public Counter<Boo> {

};


template<class ConcreateAnimal>
class Animal {
public:
    std::string who() const {
        return static_cast<const ConcreateAnimal*>(this)->who();
    }
};

template<class T>
void who_am_i(Animal<T>& animal) {
    std::cout << animal.who() << std::endl;
}



class Dog : public Animal<Dog> {
public:
    std::string who() const {
        return "dog";
    }
};

class Cat : public Animal<Cat> {
public:
    std::string who() const {
        return "cat";
    }
};


int main() {

    Cat c;
    Dog d;

    who_am_i(c);
    who_am_i(d);

    // Boo b;
    // std::cout << Boo::created << std::endl;
    // // Base d;
    // // Base* b =  new Base();

    // //b.func();


    // Derived* d2 = dynamic_cast<Derived*>(b);

    // d2->func();


    // Boo b("12345");

    // Foo f = static_cast<Foo>(b);


    // const
    // int i = 1;
    // const int* cpi = &i;

    // int* pi = const_cast<int*>(cpi);

    // *pi = 100500;


    // //std::cout << i << std::endl;

    // char* str = "Hello world";
    // const char* cstr = str;

    // char* str2 = const_cast<char*>(cstr);

    // str[0] = 'A';

    // Foo f;
    // Boo b;

    // func((Foo*)&b);


    // int i = 1;
    // int* pi = &i;
    // double* pd = (double*)pi;


    // std::cout << *pd << std::endl;
}