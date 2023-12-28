
#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>	// std::istringstream
#include <vector>
#include <deque>
#include <ctime>	// std::clock
#include <chrono>	// CLOCKS_PER_SEC
#include <iomanip>	// std::fixed, std::setprecision

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
	std::size_t n = vec_input.size();
	std::cout << "Before: ";
	printInput(vec_input);

	std::clock_t v_start = std::clock();
	sortVector(vec_input);
	std::clock_t v_end = std::clock();
	
	std::cout << "After: ";
	printInput(vec_input);

	std::cout << "Time to process a range of " << n << " elements with std::vector<int>: " << \
		std::fixed << std::setprecision(6) << static_cast<double>(v_end - v_start) / CLOCKS_PER_SEC \
		<< " µs" << std::endl;
	if (getInput(deq_input, argv) == 1)
		return EXIT_FAILURE;

	std::clock_t d_start = std::clock();
	sortDeque(deq_input);
	std::clock_t d_end = std::clock();

	std::cout << "Time to process a range of " << n << " elements with std::deque<int>: " << \
		std::fixed << std::setprecision(6) << static_cast<double>(d_end - d_start) / CLOCKS_PER_SEC \
		<< " µs" << std::endl;
	return EXIT_SUCCESS;
}
