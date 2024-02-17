#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template<typename T>
void	iter(T* array, size_t len, void funct(T const&)) {
	for (size_t i = 0; i < len; i++) {
		funct(array[i]);
	}
}

template<typename T, typename P>
void	iter(T* array, size_t len, void funct(P&)) {
	for (size_t i = 0; i < len; i++) {
		funct(array[i]);
	}
}

template<typename T, typename R, typename P>
void	iter(T* array, size_t len, R funct(P&)) {
	for (size_t i = 0; i < len; i++) {
		funct(array[i]);
	}
}

#endif /* ITER_HPP */
