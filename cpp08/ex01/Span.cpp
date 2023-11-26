
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

void Span::addNumber(int nbr) {
	if (_maxSize > _storage.size())
		_storage.push_back(nbr);
	else
		throw StorageIsFull();
}
