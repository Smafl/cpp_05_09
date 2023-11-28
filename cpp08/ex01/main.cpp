
#include "Span.hpp"
#include <iostream>

int main()
{
	Span small(200);
	try {
		small.addNumber(20);
		small.addNumber(20);
		small.addNumber(20);
		int a[] = {10, 20, 30, 40};
		small.addRange(a, a + 4);
		small.printArray();
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "Shortest span is " << small.shortestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "Longest span is " << small.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	// Span big;
	// try {
	// 	big.addRange();
	// } catch (const std::exception &e) {
	// 	std::cout << e.what() << std::endl;
	// }
	// try {
	// 	std::cout << "Shortest span is " << big.shortestSpan() << std::endl;
	// } catch (const std::exception &e) {
	// 	std::cout << e.what() << std::endl;
	// }
	// try {
	// 	std::cout << "Longest span is " << big.longestSpan() << std::endl;
	// } catch (const std::exception &e) {
	// 	std::cout << e.what() << std::endl;
	// }
	return 0;
}
