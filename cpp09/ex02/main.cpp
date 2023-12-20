
#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1) {
		std::cerr << "Error: expected a positive integer sequence as argument" << std::endl;
		return EXIT_FAILURE;
	}
	try {
		PmergeMe array(argv);

		std::cout << "Before: ";
		array.printVector();
	} catch (const Exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return EXIT_SUCCESS;
}
