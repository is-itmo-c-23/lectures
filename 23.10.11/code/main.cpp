#include <cstdio>
#include <unistd.h>

#include <iostream>




const float PI = 3.1415f;

int SomeGlobalValue = 1;

// void SomeFunc() {
// }

void SomeFunc() {
    char* str = "Hello world";
    int i = 0;

    std::cout <<  "-----\n";
    std::printf("Text segment %p\n", str);
    std::printf("Stack segment %p\n", &i);

    std::cout <<  "-----\n";
}


int main(int argc, char* argv[]) {
    int i = 0;
   // int arr[10];
    char* str = "Hello world";

    std::printf("Process id: %d\n", getpid());

    std::printf("Data segment: %p\n", &PI);
    std::printf("BSS segment %p\n", &SomeGlobalValue);
    std::printf("Text segment %p\n", str);
    std::printf("Code segment %p\n", &SomeFunc);
    std::printf("Stack segment %p\n", &i);
    std::printf("Stack segment %p\n", arr);

    SomeFunc();

    std::make_shared<int>

    getchar();
    return 0;
}



// const float PI = 3.1415f;



// int SomeGlobalValue = 1;

// void SomeFunc() {
//     char* str = "Hello world";
//     int i = 0;

//     std::cout <<  "-----\n";
//     std::printf("Text segment %p\n", str);
//     std::printf("Stack segment %p\n", &i);

//     std::cout <<  "-----\n";
// }


// int main(int argc, char* argv[]) {
//    int i = 0;
//    const char* str = "Hello world";

//    std::printf("Process id: %d\n", getpid());

//     std::printf("Data segment: %p\n", &PI);
//     std::printf("BSS segment %p\n", &SomeGlobalValue);
//     std::printf("Text segment %p\n", str);
//    std::printf("Code segment %p\n", &SomeFunc);
//    std::printf("Stack segment %p\n", &i);


// //   SomeFunc();

//    getchar();
//    return 0;
// }

