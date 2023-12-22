
#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1) {
		std::cerr << "Error: expected a positive integer sequence as argument" << std::endl;
		return EXIT_FAILURE;
	}
	PmergeVector pmVector;
	try {
		pmVector.getInput(argv);
		std::cout << "Before: ";
		pmVector.printVector();
		std::cout << std::endl;
		pmVector.makePair();

		// PmergeList lArray(argv);
		// lArray.printList();
	} catch (const Exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return EXIT_SUCCESS;
}
