#include <iostream>

#include <numeric>
#include <stdlib.h>


#include <string_view>


// 2й полупоток
class  CRational {

public:
    explicit CRational(int numerator=0 , unsigned denominator=1) // default constructor
        : numerator_(numerator)
        , denominator_(denominator)
    {
        unsigned gcd = std::gcd(numerator_, denominator_);

        numerator_ /= gcd;
        denominator_ /= gcd;

        std::cout << "CRational()\n";
    }

    CRational(const CRational& other) // copy constructor
        : numerator_(other.numerator_)
        , denominator_(other.denominator_)
    {
        std::cout << "CRational(const CRational& other)\n";
    }

    ~CRational() {
        std::cout << "~CRational()\n";
    }


    CRational& operator=(const CRational& other) {
        std::cout << "CRational& operator=\n";

        if(&other == this)
            return *this;

        numerator_= other.numerator_;
        denominator_ = other.denominator_;

        return *this;
    }

    // void set_numerator(int value) {

    //     numerator_ = value;
    //     unsigned gcd = std::gcd(numerator_, denominator_);

    //     numerator_ /= gcd;
    //     denominator_ /= gcd;
    // }

    // void set_denominator(int value) {
    //     if(value == 0)
    //         exit(1);

    //     denominator_ = value;

    //     unsigned gcd = std::gcd(numerator_, denominator_);

    //     numerator_ /= gcd;
    //     denominator_ /= gcd;
    // }



    int numerator() const {
        return numerator_;
    }

    unsigned denominator() const {
        return denominator_;
    }

private:
    int numerator_ = 0;

private:

    unsigned denominator_ = 1;
};


void PrintRational(const CRational& value) {
    std::cout << value.numerator()
              << "/"
              << value.denominator()
              << std::endl;
}

// // copy(r5, r);
// CRational& copy(CRational& r5, const CRational r) {
//     //r5.set_numerator(r.numerator())
//     //r5.set_denumerator(r.denumerator())

//     return r5;
// }


//CRational r34;

class GeoPoint {
public:
    GeoPoint(const CRational& lat, const CRational& lon)
        : lat_(lat)
        , lon_(lon)
    {

        std::cout << "GeoPoint()\n";
    }

    ~GeoPoint() {
        std::cout << "~GeoPoint()\n";
    }

private:
    CRational lat_;
    CRational lon_;
};



class CIntArray {
public:
    CIntArray(size_t size)
        : data_(new int[size])
        , size_(size)
    {}

    ~CIntArray() {
        delete[] data_;
        data_ = nullptr;
    }

    CIntArray(const CIntArray& other)
        : data_(new int[other.size_])
        , size_(other.size_)
    {
         std::memcpy(other.data_, data_, size_);
    }

    CIntArray& operator=(const CIntArray& other) {
        if(&other == this) {
            return *this;
        }

        delete[] data_;
        size_ = other.size_;
        data_ = new int[size_];
        std::memcpy(other.data_, data_, size_);

        return *this;

    }

private:
    int* data_;
    size_t size_;
};



void func(CIntArray& r, CIntArray& p) {
    //100500
    r = p;
}


void foo(CIntArray& r, CIntArray& p) {
    //100500 lines
    func(r,p);
}

class Cow;


class T {
public:
    friend std::ostream& operator<< (std::ostream& stream, const T& t);
private:
    int value_;
};

std::ostream& operator<< (std::ostream& stream, const T& t) {
    stream << t.value_;

    return stream;
}


int main(int, char**) {

    int i = 1;
    int j = 2;

    ++i;

    i + j;

    i += j;
    std::cout << i;

    // CRational r1{1};
    // CRational r2{2};

    // ++r1;

    // r1 + r2;
    // r1 += r2;

    // ++i;
    // i++;

    // for(int i =0; i < 10; ++i)
    // (std::cout << r2) << r;








    // CIntArray arr{10};
    // arr = arr;

    // foo(arr, arr);


    // CIntArray arr2{2};



    // arr2 = arr;
    // CIntArray arr3 = arr;



    // //CRational r = 1;
    // PrintRational(static_cast<CRational>(2));


    // // CRational arr[10];

    // std::cout << "start main\n";
    // CRational r{1,2};
    // CRational r2{1,2};
    // {
    //     GeoPoint p(r, r2);
    //}

    // CRational r{1,2};
    // PrintRational(r);


    // CRational r2d2 = r;

    // CRational r5;
    // r5 = r;



    // PrintRational(r);

    // CRational r2d2= r;
    // PrintRational(r2d2);


    //const CRational r3;



    // CRational* p = new CRational(1, 2);

    // PrintRational(*p);

    // delete p;
    // //free(p);

    // // r.set_numerator(2);
    // // r.set_denominator(3);

    // // PrintRational(r);

    std::cout << "end main\n";
}









// namespace N {
//     int a;

// }



// namespace {
//     void foo() {};
// }


// static void foo() {};


// // 1й полупоток
// // /*
// // +,-,*,/ ....

// // numerator
// // denominator


// // to_string()

// // */
// class CRational {
// public:
//     explicit CRational(int numerator=0 , unsigned denominator=1) // default constructor
//         : numerator_(numerator)
//         , denominator_(denominator)
//     {

//         if(denominator_ == 0)
//             exit(1);

//         unsigned gcd = std::gcd(numerator_, denominator_);
//         numerator_ /= gcd;
//         denominator_ /= gcd;

//         std::cout << "CRational()\n";
//     }

//     CRational(const CRational& other) // copy constructor
//         : numerator_(other.numerator_)
//         , denominator_(other.denominator_)
//     {
//         std::cout << "CRational(const CRational& other)\n";
//     }

//     CRational& operator=(const CRational& other) {
//         std::cout << "operator=\n";

//         if(&other == this)
//             return *this;

//         numerator_= other.numerator_;
//         denominator_ = other.denominator_;

//         return *this;
//     }


//     ~CRational() {
//         // erase resources if needed
//         std::cout << "~CRational\n";
//     }

//     int numerator() const {
//         //func();
//         return numerator_;
//     }

//     unsigned denumerator() const {
//         return denominator_;
//     }

// private:


//     int numerator_ = 0;
//     unsigned denominator_ = 1;
// };

// //CRational r;


// class GeoPoint {
// public:
//     GeoPoint() = default;

//     GeoPoint(int lat, int lon)
//         : lat_(lat)
//         , lon_(lon)
//     {}


//     GeoPoint(const CRational& lat, const CRational& lon)
//         // : lat_(lat)
//         // , lon_(lon)
//     {
//         lat_ = lat;
//         lon_ = lon;
//         std::cout << "GeoPoint()\n";
//     }

//     ~GeoPoint() {
//         std::cout << "~GeoPoint()\n";
//     }

//    GeoPoint(const GeoPoint&) = delete;

// private:
//     CRational lat_;
//     CRational lon_;
// };


// void PrintRational(const CRational& number) {
//     std::cout << number.numerator()
//               << '/'
//               << number.denumerator()
//               << std::endl;
// }

// class NonCopyable {
// public:
//     // NonCopyable (const NonCopyable&) = delete;
//     // NonCopyable& operator = (const NonCopyable&) = delete;

//     NonCopyable () = default;
//     ~NonCopyable () = default; /// Protected non-virtual destructor
// private:
//     NonCopyable (const NonCopyable&){};
//     NonCopyable& operator = (const NonCopyable&){};

// };

// class NP {
// public:
//     int value() const {
//         return value_;
//     }

// private:
//     int value_ =  3;
// };

// class P {
// public:
//     bool operator==(const NP& other) {
//         return value_ == other.value();
//     }

//    friend std::ostream& operator<<(std::ostream& stream, const P& t);
// private:
//     int value_ = 2;
// };

// // std::ostream& operator<<(std::ostream& stream, const T& t) {
// //     stream << t.value_;

// //     return stream;
// // }


// // bool operator==(const P& lhs, const NP& rhs) {
// //     return lhs.value_ == rhs.value_;
// // }


// int main(int, char**){

//     // int i = 1;
//     // int j = 2;

//     // i++;
//     // ++i;




//     // i + j;
//     // i += j;

//     // CRational r;
//     // CRational r2;






//     // (1 + 1) + 2;
//     // (std::cout ) << r;

//     // std::cout << 2 + (i += j) << std::endl;;
//     // std::cout << i << std::endl;
//     // i = 1;
//     // std::cout << ++i + i++ << std::endl;


//     // CRational* p = (CRational*)malloc(sizeof(CRational));
//     // PrintRational(*p);

//     //CRational r = 1;
//     //PrintRational(static_cast<CRational>(2));

//     // CRational r1(1,2);
//     // CRational r2(2,3);
//     // GeoPoint p{r1, r2};
//     //GeoPoint p;
//     //GeoPoint p2 = p;
//     // //std::cout << "start main\n";
//     // float f = 1.0/2;
//     // const CRational r(1, 2) ;
//     // PrintRational(r);



//     // CRational r5 = r;
//     // CRational r6;
//     // r6 = r;
//     //CRational r2(2, 4) ;
//     // CRational r3(;
//     // CRational r4{2};

//     //CRational* p = (CRational*)malloc(sizeof(CRational));
//     //CRational* p = new CRational();

//    // delete p;

// //    std::cout << r.numerator() << std::endl;
//     //std::cout << r2.numerator() << std::endl;
//    // std::cout << "end main\n";

// }
