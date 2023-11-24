
#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T *array, std::size_t len, F func) {
	for (std::size_t i = 0; i != len; i++) {
		func(array[i]);
	}
}

// correct but doesn't work with functor
// template <typename T>
// void iter(T *array, std::size_t len, void (*func)(T &)) {
// 	for (std::size_t i = 0; i != len; i++) {
// 		func(array[i]);
// 	}
// }

template <typename T>
void plusOne(T &i) {
	++i;
}

template <typename T>
void printArray(T *array, std::size_t len) {
	for (std::size_t i = 0; i != len; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

#endif // ITER_HPP
