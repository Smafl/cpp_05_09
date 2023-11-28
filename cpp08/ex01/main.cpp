
#include "Span.hpp"
#include <iostream>

int main()
{
	// Span small(200);
	// try {
	// 	small.addNumber(20);
	// 	small.addNumber(20);
	// 	small.addNumber(20);
	// 	int a[] = {10, 20, 30, 40};
	// 	small.addRange(a, a + 4);
	// 	small.printArray();
	// 	int b[] = {10, 20, 30, 40, 6, 232, 756, 12, 9, 4};
	// 	small.addRange(b, b + 10);
	// 	small.printArray();
	// } catch (const std::exception &e) {
	// 	std::cout << e.what() << std::endl;
	// }
	// try {
	// 	std::cout << "Shortest span is " << small.shortestSpan() << std::endl;
	// } catch (const std::exception &e) {
	// 	std::cout << e.what() << std::endl;
	// }
	// try {
	// 	std::cout << "Longest span is " << small.longestSpan() << std::endl;
	// } catch (const std::exception &e) {
	// 	std::cout << e.what() << std::endl;
	// }

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}
