
#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>	// std::copy
#include <exception>

class Span {
private:
	std::vector<int> _storage;
	unsigned int _maxSize;
public:
	Span();
	explicit Span(unsigned int n);
	Span(const Span &other);
	~Span();

	Span &operator=(const Span &other);

	unsigned int getMaxSize() const;
	
	void addNumber(int nbr);

	template<typename It>
	void addRange(It begin, It end) {
		std::size_t oldSize = _storage.size();
		std::size_t count = end - begin;
		unsigned int space = _maxSize - static_cast<unsigned int>(oldSize);
		if (space < count)
			throw StorageIsFull();
		_storage.resize(oldSize + count);
		std::copy(begin, end, _storage.begin() + oldSize);
	}

	int shortestSpan();
	int longestSpan();

	class StorageIsFull : public std::exception {
	public:
		const char *what() const throw();
	};

	class SpanCannotBeFound : public std::exception {
	public:
		const char *what() const throw();
	};

	void printArray() const;

};

void seedRandomGenerator();
int getRandNbr();

#endif // SPAN_HPP
