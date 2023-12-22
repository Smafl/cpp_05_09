
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include  <list>
#include <utility>	// std::pair

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

class PmergeVector {
private:
	std::vector<int> _input;
	std::vector<std::pair<int, int> > _pairs;
	int _unpairInt;
	// std::vector<int, int> _main;	
	// std::vector<int, int> _second;

public:
	PmergeVector();
	// explicit PmergeVector(char **argv);
	// PmergeVector(const PmergeVector &other); // to do
	~PmergeVector();

	// PmergeVector &operator(const PmergeVector &other); // to do

	void getInput(char **argv);
	void makePair();
	// void sortPair();
	void printVector() const;
};

// class PmergeList {
// private:
// 	std::list<int> _list;

// public:
// 	PmergeList();
// 	explicit PmergeList(char **argv);
// 	// PmergeList(const PmergeList &other); // to do
// 	~PmergeList();

// 	// PmergeList &operator(const PmergeList &other); // to do

// 	void printList() const;
// };

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
