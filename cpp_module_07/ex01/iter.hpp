#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template<typename T> // size_t or T???
void    iter(T* array, size_t len, T* funct(T*)) {
    for (size_t i = 0; i < len; i++) {
        funct(array + i);
    }
}

template<typename T>
T    print(T element) {
    std::cout << "print: " << *element << std::endl;

    return NULL;
}

#endif /* ITER_HPP */
