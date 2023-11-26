
#include "Span.hpp"
#include <algorithm> // std::copy

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
