
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <class T>
class Array {
private:
	T *_array;
	unsigned int _size;
public:
	Array() : _array(NULL), _size(0) { };

	Array(unsigned int n) : _array(new T[n]), _size(n) { };

	Array(const Array &other) : _array(new T[other._size]), _size(other._size) {
		for (unsigned int i = 0; i != _size; i++) {
			_array[i] = other._array[i];
		}
	}

	~Array() {
		if (_array != NULL)
			delete [] _array;
	};

	Array &operator=(const Array &other) {
		if (this != &other) {
			_size = other._size;
			_array = new T[_size];
			for (unsigned int i = 0; i != _size; i++) {
				_array[i] = other._array[i];
			}
		}
		return *this;
	}

	T &operator[](unsigned int index) {
		if (index >= _size)
			throw std::out_of_range("index is out of range");
		return _array[index];
	}

	unsigned int size() {
		return _size;
	}
};

#endif // ARRAY_HPP
