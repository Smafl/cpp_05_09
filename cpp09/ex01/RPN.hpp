
#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

struct Exception {
	enum Cause {
		EMPTY_INPUT,
		OUT_OF_RANGE,
		EMPTY_STACK
	};

	Cause cause;

	explicit Exception(Cause cause) : cause(cause) { }

	const char *what() const throw() {
		switch (cause) {
			case EMPTY_INPUT: return "Error: no input";
			case OUT_OF_RANGE: return "Error: number is out of range";
			case EMPTY_STACK: return "Error";
		}
	}
};

class Calc {
private:
    std::stack<int> _st;
public:
    Calc();
    // Calc(const Calc &other) { }
    explicit Calc(char *input);
    ~Calc();

    // Calc &operator=(const Calc &other) { }

	void push(int nbr);
	void pop();
	int top() const;

	void printStack() const;
};

#endif // RPN_HPP

// move constructors in .cpp

/*
- empty string
- out of range
- negative
- 3 numbers in a row
- 2 operations in a row
- number at the end of string without operation
*/

/*
if operator
	top, pop
	calculate
	push
*/
