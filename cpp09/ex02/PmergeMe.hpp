
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

class PmergeMe {
private:
	std::vector<int> _vec;
	std::deque<int> _deq;

public:
	PmergeMe();
	// PmergeMe(const PmergeMe &other);
	~PmergeMe();

	// PmergeMe &operator(const PmergeMe &other);
};

#endif // PMERGEME_HPP
