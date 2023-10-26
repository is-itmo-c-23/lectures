
#include <iostream>


// 2 полупоток




// void swap(int*& a, int*& b) {
//     int* tmp = a;
//     a = b;
//     b = tmp;
// }


// void swap(int* a, int* b) {
//     if(a == nullptr) {
//         return ;
//     }

//     int tmp = *a;
//     *a = *b;
//     *b = tmp;
// }



int foo() {
    float k = 10.4;
    return k;
}

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

struct Boo {
    int array[1000];
};


// void boo(Boo b) {
//     std::cout << &b << std::endl;
// }

// void boo(Boo* b) {
//     if(b == nullptr) {
//         // ....
//     }
//     std::cout << &b << std::endl;
// }

// void boo(Boo& b) {
//     b.array[0] = 100500;
//     std::cout << &b << std::endl;
// }


// void boo(const Boo& b, int i) {
//     Boo* pb = &b;
//     //b.array[0] = 100500;
//     std::cout << &b << std::endl;
// }

void boo(const Boo& b, int i) {
    Boo tmp = b;
    tmp.array[0] = 100500;
    std::cout << &b << std::endl;
}

void boo(Boo b, int i) {
    b.array[0] = 100500;
    std::cout << &b << std::endl;
}



void print() {
    std::cout << std::endl;
}
void print(int x) {
    std::cout << "int  "<< x << std::endl;
}

void print(int* x) {
    std::cout << "int*  "<< *x << std::endl;
}
// void print(long l) {
//     std::cout << "long  " << l << std::endl;
// }

void print(const char* str) {

    std::cout << "str  "  << str << std::endl;
}
void print(int x, int y) {
    std::cout << x << " " << y << std::endl;
}

int main() {
    // print();
    // print(10);
    // print("Hello world!");
    // print(10, 20);
    // print(20.1);
    print(nullptr);



    // Boo b;
    // int i = 2;
    // std::cout << &b << std::endl;

    // boo(b, 2);





    return 0;


    int i = 100500;
    int j = 2;
    int x = foo();

    swap(j, i);


    std::cout << &i << "   " << &x << std::endl;
    std::cout << i << "   " << x << std::endl;
    swap(j, i);

    // std::cout << x << std::endl;

    // int i = 10;
    // int* pi = &i;
    // int j = 20;
    // int* pj = &j;




    // swap(&pi, &pj);



    // int** ppi = &pi;
    // int*** ppi = p&pi;






    // // const int i = 10;
    // int& j = i;
    // j = 1;



    //int& k; // error: ‘k’ declared as reference but not initialized

    // j = 20;

    // std::cout << i << std::endl;
    // std::cout << &i << " " << &j << std::endl;



    // const int& r = i;
    // std::cout << r << std::endl;
    // i = 100500;
    // std::cout << r << std::endl;

      // r = 21; // error assignment of read-only reference ‘r’



    return 0;
}


/// 1 полупоток
// void swap3(int* a, int* b, int* c) {}

// void swap(int* a, int* b) {

//     if(a == nullptr && b == nullptr) {
//         return;
//     }

//     if(a == nullptr || b == nullptr) {
//         exit(1);
//     }

//     int tmp = *a;
//     *a = *b;
//     *b = tmp;
// }


// void swap(int& a, int& b) {
//     int tmp = a;
//     a = b;
//     b = tmp;
// }

// int foo() {
//     int i = 20;
//     return i;
// }

// struct Foo {
//     int array[1000];
// };



// //void boo(const Foo& f) {
// //void boo(Foo& f) {
// void boo(Foo f) {
//     Foo f1 = f;
//     std::cout << &f << std::endl;
//     f1.array[0] = 1;
// }

// int main() {


//     // int i = 10;
//     // int& j = i;
//     // int& k = &j;


//     std::cout << (0 == NULL)  << std::endl;

//     // Foo f;
//     // std::cout << &f << std::endl;
//     // boo(f);


//     // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9 ,10, 11, 12};
//     // int& x = foo();
//     // swap(arr[0], arr[1]);
//     // int y = 100;

//     // std::cout << x << std::endl;

//     // return 0;



//     // int i = 10;
//     // int& j = i;
//     // //int& k; // error: ‘k’ declared as reference but not initialized
//     // j = 20;


//     // std::cout << i << std::endl;

//     // i = 30;
//     // std::cout << j << std::endl;

//     // std::cout << &i << " " << &j << std::endl;
//     // const int& r = i;
//     // // r = 21; // error assignment of read-only reference ‘r’
//     // return 0;


//     // int x = 1;


//     // int y = 2;


//     // int* px = &x;
//     // int* py = nullptr;

//     // int*& rpy = py;

//     // std::cout << *rpy << std:endl;

//     // std::cout  << x << "    " << y << std::endl;
//     // swap(x, y);
//     // std::cout  << x << "    " << y << std::endl;

//     // int* i = new int{10};
//     // int*& j = i;

//     // //std::cout << *i << "   " << *j << std::endl;
//     // delete i;
//     // i = nullptr;

//     // std::cout << i << "   " << j << std::endl;


// }