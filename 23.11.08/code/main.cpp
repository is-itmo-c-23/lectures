#include <iostream>


class CRational {
public:
    CRational(int numerator, unsigned denominator) // default constructor
        : numerator_(numerator)
        , denominator_(denominator)
    {}

    CRational(const CRational& other) // copy constructor
        : numerator_(other.numerator_)
        , denominator_(other.denominator_)
    {}


    int numerator() const {
        return numerator_;
    }

    unsigned denominator() const {
        return denominator_;
    }

private:
    int numerator_;
    unsigned denominator_;
};


int main(int, char**){
    CRational r{1, 2};

    CRational r2d2 = r;


    std::cout << r.numerator() << std::endl;
}
