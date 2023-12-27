
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

class PairBase {
protected:
	PairBase() { };
	// PairBase(const PairBase &other);
	PairBase &operator=(const PairBase &);
public:
	virtual ~PairBase() { } // to do

	virtual int getNbr() const = 0;

};

class Pair : public PairBase {
private:
	Pair();
	// to do: copy + assigned
	PairBase *_max;
	PairBase *_min;
public:
	Pair(PairBase *f, PairBase *s) {
		if (f->getNbr() > s->getNbr()) {
			_max = f;
			_min = s;
		}
		else {
			_max = s;
			_min = f;
		}
	}
	~Pair() { } // to do

	int getNbr () const {
		return _max->getNbr();
	}

	PairBase *getMax() const {
		return _max;
	}

	PairBase *getMin() const {
		return _min;
	}
};

class Unpair : public PairBase {
private:
	int _nbr;
	Unpair();
	// to do: copy + assigned
public:
	explicit Unpair(int nbr) : _nbr(nbr) { }
	~Unpair() { } // to do

	int getNbr() const {
		return _nbr;
	}
};

void sort(std::vector<int> &input);

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
