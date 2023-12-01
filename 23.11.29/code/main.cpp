#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

//2й полупоток

#define MULT(M)          \
int mult##M(int value) { \
    return M * value;    \
}                        \





MULT(10)

// int mult10(int value) {
//     return 10 * value;
// }

// int mult11(int value) {
//     return 11 * value;
// }

// int mult12(int value) {
//     return 12 * value;
// }


class Mult {
public:
    Mult(int mult)
        : mult_(mult)
    {}

    int operator()(int value) {
        ++counter_;
        return mult_ * value;
    }

    size_t counter() const {
        return counter_;
    }

private:
    int mult_;
    size_t counter_;
};

class CFileDescriptor {
public:
    explicit CFileDescriptor(const char* path, const char* mode) {
        file_ = fopen(path, mode);
        if(file_ == nullptr) {
             // throw some exception (see next lection)
        }
    }
    operator FILE*() {
       return file_;
    }
    ~CFileDescriptor(){
      if(file_ != nullptr)
        fclose(file_);
    }

private:
    FILE* file_;
};



class Base {
public:
    void foo() { }

protected:
    void boo() {}
    int pr_value_ = 1;

private:
    int value_ = 2023;
};

class Derrived : public Base {
public :
    void func () {
        value_ = 0;
    }
private:
    int some_value_;
};

int main(int, char**){
    Derrived b;
    b.foo();



    return 0;
    CFileDescriptor file("somefile.txt", "w");
    // FILE* file = fopen("somefile.txt", "w");
    // if(file == nullptr) {
    //     exit(1);
    // }

//     bool b = true;

//     fprintf(file, "adsad");

//     if(b) {
//        // fclose(file);
//         return 0;
//     }

//     if(b) {
//       //  fclose(file);
//         return 0;
//     }

//    /// fclose(file);


//     // int x = 1;
//     // Mult mult10_new{10};










    // std::cout << mult10(x) << std::endl;
    // std::cout << mult10_new(x) << std::endl;



    std::vector<int> v = {1,2,3,4,5};

    std::transform(v.begin(), v.end(), v.begin(), Mult{11});

    // for(int& x : v) {
    //     x = mult10(x);
    // }

    for(int x : v)
        std::cout << x << " ";




    return 0;
}


// 1й полупоток
// int mult10(int value) {
//     return 10 * value;
// }

// int mult11(int value) {
//     return 10 * value;
// }


// class Mult {
// public:
//     Mult(int mult)
//         : mult_(mult)
//     {}

//     int operator()(int value) const {
//         //++counter_;
//         return mult_ * value;

//     }

// private:
//     int mult_;
//     size_t counter_;
// };

// class CFileDescriptor {
// public:
//     explicit CFileDescriptor(const char* path, const char* mode) {
//         file_ = fopen(path, mode);
//         if(file_ == nullptr) {
//             // throw some exception (see next lection)
//         }
//     }

//     operator FILE*() {
//         return file_;
//     }


//     ~CFileDescriptor(){
//         if(file_ != nullptr)
//         fclose(file_);
//     }

// private:
//     FILE* file_;
// };


// class Base {
// public:
//     int foo() const {
//         return value_;
//     };

// protected:
//     void boo() {};
//     int pr_value_;

// private:
//     int value_ = 2023;
// };

// class Derrived : publicx Base {
// public:
//     void func () {
//         foo();
//     }
// private:
//     int x_;

// };

// void fun(Base b) {
//     std::cout << b.foo() << std::endl;
// }

// int main(int, char**){

//     Derrived b;
//     //b.foo();
//     fun(b);


//     //FILE* file = fopen("somefile.txt", "w");

//     // if(file == NULL)
//     //     return 1;

//     //fprintf(file, "asdaad" );
//     //return 0;

//     ///.......


//     //fclose(file);


//     CFileDescriptor file{"somefile.txt", "w"};

//     fprintf(file, "asdaad" );





//     // int x = 1;
//     // Mult mult10_new{10};


//     // // std::cout << mult10_new(x) << std::endl;
//     // // std::cout << mult10(x) << std::endl;

//     // std::vector<int> v = {1,2,3,4,5};

//     // int mult = 12;
//     // std::transform(v.begin(), v.end(), v.begin(), Mult{mult});
//     // // for(int& x : v) {
//     // //     x = mult10(x);
//     // // }

//     // for(int x : v) {
//     //     std::cout << x << " ";
//     // }


// }
