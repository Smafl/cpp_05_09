
#include "Span.hpp"
#include <iostream>

int main()
{
	Span small(3);
	try {
		small.addNumber(5);
		small.addNumber(10);
		small.addNumber(15);
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << small.longestSpan() << std::endl;
	Span big(0);
	try {
		std::cout << big.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
