
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
	Span big(small);

	return 0;
}
