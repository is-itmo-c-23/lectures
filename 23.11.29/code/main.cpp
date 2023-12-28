#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <fstream>

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

    virtual void func() const {
        std::cout << "Base\n";
    }

    void foo() { }


    virtual ~Base() {
        std::cout << "~Base()\n";
    }


    friend std::ostream& operator<<(std::ostream& stream, const Base& value);



protected:

    virtual std::ostream& printImpl(std::ostream& stream) const {
        stream << "<<Base>>";
        return stream;
    }

    void boo() {}
    int pr_value_ = 1;

private:
    int value_ = 2023;
};

std::ostream& operator<<(std::ostream& stream, const Base& value) {
    return value.printImpl(stream);
}



class Derrived : public Base {
public :
    void func() const override {
        std::cout << "Derrived\n";
    }

    ~Derrived() {
        std::cout << "~Derrived()\n";
    }

protected:
    std::ostream& printImpl(std::ostream& stream) const override {
        stream << "<<Derrived>>";
        return stream;
    }

private:
    int some_value_;
};




class Derrived2 : public Base {
public:
     void func() const override {
        std::cout << "Derrived2\n";
    }

    ~Derrived2() {
        std::cout << "~Derrived2()\n";
    }

protected:
     std::ostream& printImpl(std::ostream& stream) const override {
        stream << "<<Derrived2>>";
        return stream;
    }
};



class CLogger {
public:
    virtual void Log(const char* message) = 0;

    void func(int x ){
        std::cout << "void func(int x)\n";
    }

    virtual ~CLogger() = default;
};


class CConsoleLogger : public CLogger {
public:
    void Log(const char* message) {
        std::cout << message << std::endl;
    }
};


class CFileLogger : public CLogger {
public:
    CFileLogger(const char* filename)
        : stream_(filename)
    {}

    ~CFileLogger() {
        stream_.close();
    }

    CFileLogger(const CFileLogger&) = delete;

    CFileLogger& operator=(const CFileLogger&) = delete;

    void Log(const char* message) {
        stream_ << message << std::endl;
    }

private:
    std::ofstream stream_;
};


int Increase(int x, CLogger& logger) {
    ++x;
    logger.Log("Increase!\n");
    logger.func(10);
    return x;
}

int main(int, char**){

    // CLogger* log = new CConsoleLogger();



    // log.Log();

    // delete log;

    // CConsoleLogger logger;
    // Increase(10, logger);

    // // logger.func(10);
    // return 0;


    std::vector<Base*> bases;

    bases.push_back(new Derrived2{});
    bases.push_back(new Derrived{});
    bases.push_back(new Derrived2{});
    bases.push_back(new Base{});
    bases.push_back(new Derrived2{});
    bases.push_back(new Derrived{});


    for(auto b : bases)
        std::cout << *b << std::endl;


    for(auto b : bases)
        delete b;

    // CLogger baseLogger;
    // Increase(10, baseLogger);

    // CConsoleLogger logger;
    // Increase(10, logger);

    // CFileLogger fileLogger{"out.txt"};
    // Increase(10, fileLogger);




    return 0;
    // Derrived b;
    // b.foo();



    // return 0;
    // CFileDescriptor file("somefile.txt", "w");
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

//     Base() {
//         std::cout << "Base()\n";
//     }

//     Base(const Base&) {
//         std::cout <<  "Base(const Base&)\n";
//     }

//     virtual void func() const = 0;

//     int foo() const {
//         return value_;
//     };

//     virtual ~Base() {
//         std::cout << "~Base()\n";
//     }

// protected:
//     void boo() {};
//     int pr_value_;

// private:
//     int value_ = 2023;
// };

// class Derrived : public Base {
// public:

//     Derrived() {
//         std::cout << "Derrived()\n";
//     }

//     Derrived(const Derrived&) {
//         std::cout << "Derrived(const Derrived&)\n";
//     }

//     void func() const override {
//         std::cout << "Derrived\n";
//     }

//     ~Derrived() {
//         std::cout << "~Derrived\n";
//     }
// private:
//     int x_;

// };


// class Derrived2 : public Base {
// public:
//     void func() const override {
//         std::cout << "Derrived2\n";
//     }
// };

// void fun(Base b) {
//     std::cout << b.foo() << std::endl;
// }


// class CLogger {
// public:
//     virtual void Log(const char* message, bool b) = 0;

//     virtual ~CLogger() {

//     }
//     void func() {

//     }
// };

// class CConsoleLogger : public CLogger {
// public:
//     void Log(const char* message, bool b) final {
//         func();
//         std::cout << message << std::endl;
//     }
// };


// class CFileLogger : public CLogger {
// public:
//     CFileLogger(const char* filename)
//         : stream_(filename)
//     {}

//     ~CFileLogger() {
//         stream_.close();
//     }

//     CFileLogger(const CFileLogger&) = delete;
//     CFileLogger& operator=(const CFileLogger&) = delete;

//     void Log(const char* message, bool b) {
//         stream_ << message << std::endl;
//     }

// private:
//     std::ofstream stream_;
// };


// int Increase(int x, CLogger& logger) {
//     ++x;
//     logger.Log("Increase\n", false);

//     return x;
// }


// void some_func(Base b) {
//     b.func();
// }


// int main(int, char**){

//     // Base b;

//     // some_func(b);
//     Derrived d;

//     some_func(d);

//     return 0;
//     // Base bases[10];
//     // std::vector<Base*> bases;

//     // bases.push_back(new Derrived2());
//     // bases.push_back(new Derrived());
//     // bases.push_back(new Base());
//     // bases.push_back(new Derrived());
//     // bases.push_back(new Derrived2());


//     // for(auto& b : bases)
//     //     std::cout << b;


//     // for(auto& b : bases)
//     //     delete b;



//     // CConsoleLogger logger;

//     // Increase(10, logger);

//     // CLogger baseLogger;

//     // Increase(10, baseLogger);


//     // Derrived b;
//     // //b.foo();
//     // fun(b);


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
