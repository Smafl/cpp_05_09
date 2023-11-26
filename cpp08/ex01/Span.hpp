
#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
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
	// void shortestSpan();
	int longestSpan();

	class StorageIsFull : public std::exception {
	public:
		const char *what() const throw() {
			return "storage is full";
		}
	};

	class SpanCannotBeFound : public std::exception {
	public:
		const char *what() const throw() {
			return "Span cannot be found";
		}
	};
};

#endif // SPAN_HPP
