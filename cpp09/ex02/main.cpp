
#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>	// std::istringstream
#include <vector>
#include <deque>

template <typename T>
void printInput(const T &input) {
	for (typename T::const_iterator it = input.begin(); it != input.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template <typename T>
int getInput(T &input, char **argv) {
	int i = 1;
	while (argv[i]) {
		std::istringstream is(argv[i]);
		int nbr;
		while (is.good()) {
			is >> nbr;
			if (is.fail()) {
				std::cerr << "Error: bad input" << std::endl;
				return EXIT_FAILURE;
			}
			if (nbr < 0) {
				std::cerr << "Error: bad input" << std::endl;
				return EXIT_FAILURE;
			}
			input.push_back(nbr);
			is >> std::ws;
		}
		i++;
	}
	return EXIT_SUCCESS;
}

int main(int argc, char **argv)
{
	if (argc == 1) {
		std::cerr << "Error: expected a positive integer sequence as argument" << std::endl;
		return EXIT_FAILURE;
	}
	std::vector<int> vec_input;
	std::deque<int> deq_input;

	if (getInput(vec_input, argv) == 1)
		return EXIT_FAILURE;
	std::cout << "Before: ";
	printInput(vec_input);
	sortVector(vec_input);
	std::cout << "After: ";
	printInput(vec_input);

	if (getInput(deq_input, argv) == 1)
		return EXIT_FAILURE;
	printInput(deq_input);
	sortDeque(deq_input);
	printInput(deq_input);
	return EXIT_SUCCESS;
}
