#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <forward_list>
#include <list>
#include <deque>

// 1й полупоток
// template<typename T, size_t SIZE>
// class CStackAllocator {
// public:
//     typedef size_t size_type ;
//     typedef ptrdiff_t difference_type ;
//     typedef T* pointer ;
//     typedef const T* const_pointer ;
//     typedef T& reference ;
//     typedef const T& const_reference ;
//     typedef T value_type ;


//     template<typename U>
//     struct rebind {
//         typedef CStackAllocator<T, SIZE> other;
//     };


//     pointer allocate(size_type n) {
//         pointer result = buffer_ + size_;

//         std::cout << "Allocate " << result << "  " <<  n << std::endl;
//         size_ += n;

//         return result;
//     }

//     void deallocate(pointer p, size_type n) {
//         std::cout << "Deallocate " << p << " " << n << std::endl;
//     }

// private:
//     T buffer_[SIZE];
//     size_t size_ = 0;


// };

// struct Foo {
//     int i;
//     int j;
// };

// bool operator==(const Foo& lhs, const Foo& rhs) {
//     return lhs.i == rhs.i && lhs.j == rhs.j;
// }


// namespace std {

// template<>
// struct hash<Foo> {
//     size_t operator()(const Foo& value) {
//          std::hash<int> h;
//          return h(h(value.i)) ^ h(value.j);
//     }
// };

// } // namespace std


// // LIFO
// template<typename T, typename Container = std::deque<T>>
// class MyStack {

//     static_assert(std::is_same_v<T, typename Container::value_type>, "Bla");
// public:
//     void push(const T& value) {
//         data_.push_back(value);
//     }

//     void pop() {
//         data_.pop_back();
//     }

//     T top() {
//         return data_.back();
//     }

//     bool empty() const {
//         return data_.empty();
//     }

// private:
//     Container data_;
// };


// template<typename Container>
// class MyBackInsertIterator {

//     MyBackInsertIterator(Container& c)
//         : data_(c)
//     {}

//     Container& operator++() {
//         data_.push_back(0);
//         data_.pop_back();

//         return data_;

//     }
//     operator++(int);

//     operator*();

// private:
//     Container& data_;
// };

// int main(int, char**){

//     // MyStack<int, std::vector<int>> st;

//     // st.push(1);
//     // int i = st.top();
//     // bool b = st.empty();
//     // st.pop();

//     //std::unordered_set<Foo> map;


//     int arr[] = {1,2,3,4,5};
//     std::vector<int> v;
//     std::copy(arr, arr + 5, MyBackInsertIterator(v));


//     for(int i : v) {
//         std::cout << i << " ";
//     }

//     std::cout << std::endl;

// }



//2й полупоток

template<typename T, size_t SIZE>
class CStackAllocator {
public:
    typedef size_t size_type ;
    typedef ptrdiff_t difference_type ;
    typedef T* pointer ;
    typedef const T* const_pointer ;
    typedef T& reference ;
    typedef const T& const_reference ;
    typedef T value_type ;


    template<typename U>
    struct rebind {
        typedef CStackAllocator<T, SIZE> other;
    };


    pointer allocate(size_type n) {
        pointer result = buffer_ + size_;

        std::cout << "Allocate " << result << "  " <<  n << std::endl;
        size_ += n;

        return result;
    }

    void deallocate(pointer p, size_type n) {
        std::cout << "Deallocate " << p << " " << n << std::endl;
    }

private:
    T buffer_[SIZE];
    size_t size_ = 0;


};

struct  Foo {
    int i;
    int j;
};



bool operator==(const Foo& lhs, const Foo& rhs) {
    return lhs.i == rhs.i && lhs.j == rhs.j;
}


struct FooHash {
    size_t operator()(const Foo& value) const {
        return 0;
    }
};

namespace std {
template<>
struct hash<Foo> {
    size_t operator()(const Foo& value) const {
        std::hash<int> h;
        return h(value.i) ^ h(value.j);
    }
};
} // namespace std;


// LIFO
template<typename T, typename Container = std::deque<T>>
class MyStack {
public:
    void push(const T& value) {
        data_.push_back(value);
    }

    void pop() {
        data_.pop_back();
    }

    const T& top() const {
        return data_.back();
    }

    bool empty() const {
        return data_.empty();
    }

private:
    Container data_;
};

struct tag_1 {};
struct tag_2 {};
struct tag_3 : public tag_2 {};

struct TypeA {};
struct TypeB {};
struct TypeC {};

template<typename T>
struct my_traits {
    typedef tag_1 tag;
};

template<>
struct my_traits<TypeB> {
    typedef tag_2 tag;
};

template<>
struct my_traits<TypeC> {
    typedef tag_3 tag;
};


template<typename T>
void func_dispatch(const T& value, const tag_1&) {
    std::cout << "tag1\n" ;
}

template<typename T>
void func_dispatch(const T& value, const tag_2&) {
    std::cout << "tag2\n" ;
}

template<typename T>
void evaluate(const T& value) {
    func_dispatch(value, typename my_traits<T>::tag());
}

int main() {

    MyStack<int, std::vector<int>> st;
    st.push(1);
    st.top();
    st.empty();
    st.pop();
}


