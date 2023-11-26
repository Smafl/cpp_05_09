
#include "Span.hpp"
#include <algorithm> // std::copy

Span::Span() :
	_maxSize(0) { }

Span::Span(unsigned int n) :
	_maxSize(n) { }

Span::Span(const Span &other) :
	_maxSize(other._maxSize) {
		std::copy(other._storage.begin(), other._storage.end(), _storage.begin());
	}

Span::~Span() { }

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		Span newSpan(other);
		std::swap(newSpan._maxSize, _maxSize);
		std::swap(newSpan._storage, _storage);
	}
	return *this;
}

void Span::addNumber(int nbr) {
	;
}
