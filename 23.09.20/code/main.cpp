#include <iostream>


void swap(int* px, int* py) {
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}

int main(int argc, char* argv[]) {
    int x = 0;
    int y = 2;
    bool b = 1;
    std::cout << "x = " << x << " y = " << y << std::endl;

    int* px = (int*)&b;

    
    //swap(px, &y);

    std::cout << "x = " << x << " y = " << y << std::endl;

    // bool b = true;
    // long long l = 128L;
    // std::cout << sizeof(b) << std::endl;
    // std::cout << sizeof(l) << std::endl;


    // bool* pb = &b;
    // long long* pl = &l;
    // std::cout << sizeof(pb) << std::endl;
    // std::cout << sizeof(pl) << std::endl;


    // int i = 10;
    // int j = 12;
    // long l = 128L;
    // float f = 129.1;


    // std::cout << &i << std::endl;
    // std::cout << &j << std::endl;
    // std::cout << &l << std::endl;
    // std::cout << &f << std::endl;



    // for(int i = 0; i < argc; ++i)
    //     std::cout << argv[i] << " ";


    // std::cout << std::endl;
    return 0;
    // int x = 1;

    // switch (x){
    // case 1:
    //     printf( "x is 1");
    //     break;
    // case 2:
    //     printf( "x is 2");
    //     break;
    // default:
    //     printf( "unknown");
    // }
}

// 1й полупоток
// int x;
// int y;

// void func(double x) {
//     double y;
//     std::cout << "x = " << x << " y = " << y << std::endl;
// }

// void swap(int* px, int* py) {

//     int* tmp = px;
//     px = p
//     int temp;
//     temp = *px;
//     *px = *py;
//     *py = temp;
// }


// int main() {
//     // x = 21;
//     // {
//     //     int x = 10;
//     //     y = 239;
//     //     std::cout << "x = " << x << " y = " << y << std::endl;
//     //     func(y);
//     // }
//     // std::cout << "x = " << x << " y = " << y << std::endl;
//     // return 0;

//     // int i = 10;
//     // int j = 12;
//     // long l = 128L;
//     // float f = 129.1;

//     // std::cout << &i << std::endl;
//     // std::cout << &j << std::endl;
//     // std::cout << &l << std::endl;
//     // std::cout << &f << std::endl;

//     // bool b = true;
//     // long l = 128L;
//     // std::cout << sizeof(b) << std::endl;
//     // std::cout << sizeof(l) << std::endl;


//     // bool* pb = &b;
//     // long* pl = &l;
//     // std::cout << sizeof(pb) << std::endl;
//     // std::cout << sizeof(pl) << std::endl;

//     int x = 1;
//     int y = 2;

//     std::cout << "x = " << x << " y = " << y << std::endl;

//     swap(&x, &y);

//     std::cout << "x = " << x << " y = " << y << std::endl;

// }

// // int main(int argc, char* argv[]) {
// //     for(int i = 0; i < argc; ++i)
// //         std::cout << argv[i] << " ";

// //     std::cout << std::endl;
// //     return 0;
// // }


// // int main(int, char**){
// //     int n = -2;
// //     int a = 1;
// //     int b = 2;
// //     int z = 20;


// //     if (n > 0) {
// //         if(a > b)
// //             z = a;
// //     }
// //     else {
// //         z = b;
// //     }

// //   //  std::cout << z << std::endl;
// //     int x = 1;

// //     switch (x){
// //     case 1:
// //         printf( "x is 1");
// //        // break;
// //     case 2:
// //         printf( "x is 2");
// //         break;
// //     default:
// //         printf( "unknown");
// //     }


// //     return 0;
// // }
