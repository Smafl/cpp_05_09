
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
	// void longestSpan();

	class StorageIsFull : public std::exception {
	public:
		const char *what() const throw() {
			return "storage is full";
		}
	};
};

#endif // SPAN_HPP
