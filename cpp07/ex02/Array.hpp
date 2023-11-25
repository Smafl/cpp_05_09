
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
void swap(T &a, T &b) {
	T temp(a);
	a = b;
	b = temp;
}

template <class T>
class Array {
private:
	T *_array;
	unsigned int _size;
public:
	Array() : _array(new T[0]), _size(0) { };

	explicit Array(unsigned int n) : _array(new T[n]), _size(n) { };

	Array(const Array &other) : _array(new T[other._size]), _size(other._size) {
		for (unsigned int i = 0; i != _size; i++) {
			_array[i] = other._array[i];
		}
	}

	~Array() {
		delete [] _array; // no need to check NULL
	}

	void swap(Array &newArray) {
		::swap(newArray._size, this->_size);
		::swap(newArray._array, this->_array);
	}

	Array &operator=(const Array &other) {
		if (this != &other) {
			Array newArray(other);
			swap(newArray);
		}
		return *this;
	}

	T &operator[](unsigned int index) {
		if (index >= _size)
			throw std::out_of_range("index is out of range");
		return _array[index];
	}

	const T &operator[](unsigned int index) const {
		if (index >= _size)
			throw std::out_of_range("index is out of range");
		return _array[index];
	}

	unsigned int size() const {
		return _size;
	}
};

template<typename T>
void swap(Array<T> &a, Array<T> &b) {
	a.swap(b);
}

template <typename T>
void printArray(const Array<T> &array) {
	for (unsigned int i = 0; i != array.size(); i++) {
		std::cout << array[i] << " ";
	}
}

#endif // ARRAY_HPP
