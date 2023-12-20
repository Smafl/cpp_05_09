
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>

struct Exception {
	enum Cause {
		BAD_INPUT // out of range, negative, not a number
	};

	Cause cause;

	explicit Exception(Cause cause) : cause(cause) { }

	const char *what() const throw() {
		switch (cause) {
			case BAD_INPUT: return "Error: bad input";
			default: return "Unknown error";
		}
	}
};

class PmergeMe {
private:
	std::vector<int> _vec;

public:
	PmergeMe();
	explicit PmergeMe(char **argv);
	// PmergeMe(const PmergeMe &other); // to do
	~PmergeMe();

	// PmergeMe &operator(const PmergeMe &other); // to do

	void printVector() const;
};

#endif // PMERGEME_HPP

/*
algorithm:
-	take a sequence from input
-	make a sequence in ascending order of numbers from
	bigger numbers from each pair (recursively)
-	insert the remaining smallest numbers
-	insert the last number (if odd) with binary search
*/

// j(n) = j(n - 1) + 2 * j(n - 2)

// ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
