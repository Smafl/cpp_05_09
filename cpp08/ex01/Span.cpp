
#include "Span.hpp"
#include <iostream>
#include <vector>
#include <algorithm>	// std::copy, std::generate_n
#include <cstdlib>		// for rand() and srand()
#include <ctime>		// for time()

Span::Span() :
	_maxSize(0) { }

Span::Span(unsigned int n) :
	_maxSize(n) { }

Span::Span(const Span &other) :
	_storage(other._storage),
	_maxSize(other._maxSize) { }

Span::~Span() { }

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		Span newSpan(other);
		std::swap(newSpan._storage, _storage);
		std::swap(newSpan._maxSize, _maxSize);
	}
	return *this;
}

unsigned int Span::getMaxSize() const {
	return _maxSize;
}

void Span::addNumber(int nbr) {
	if (_maxSize > _storage.size())
		_storage.push_back(nbr);
	else
		throw StorageIsFull();
}

void Span::addRange(int i) {
	seedRandomGenerator();
	(void)i;
	std::generate(_storage.begin(), _storage.end(), getRandNbr);
	// std::generate_n(_storage, i, getRandNbr);
	// _storage.insert(_storage.begin(), i, getRandNbr());
}

int Span::shortestSpan() {
	std::size_t size = _storage.size();
	if (size == 0 || size == 1)
		throw SpanCannotBeFound();

	int shortSpan;
	int shortestSpan = INT_MAX;

	for (std::size_t i = 0; i != size; ++i) {
		for (std::size_t j = 1; j != size; ++j) {
			if (i != j) {
				shortSpan = std::max(_storage[i], _storage[j]) - std::min(_storage[i], _storage[j]);
				if (shortSpan == 0)
					return shortSpan;
				else if (shortestSpan > shortSpan)
					shortestSpan = shortSpan;
			}
		}
	}
	return shortestSpan;
}

int Span::longestSpan() {
	std::size_t size = _storage.size();
	if (size == 0 || size == 1)
		throw SpanCannotBeFound();
	
	std::vector<int>::iterator itMax;
	std::vector<int>::iterator itMin;

	itMax = std::max_element(_storage.begin(), _storage.end());
	itMin = std::min_element(_storage.begin(), _storage.end());
	return *itMax - *itMin;
}

const char *Span::StorageIsFull::what() const throw() {
	return "storage is full";
}

const char *Span::SpanCannotBeFound::what() const throw() {
	return "Span cannot be found";
}

void Span::printArray() const {
	for (std::size_t i = 0; i != _storage.size(); i++)
		std::cout << _storage[i] << " ";
	std::cout << std::endl;
}

void seedRandomGenerator() {
    // Seed the random number generator with the current time
    std::srand(std::time(0));
}

int getRandNbr() {
	return std::rand() / 100000;
}
