
#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

struct Exception {
	enum Cause {
		BAD_INPUT,
		LOGIC_ERROR
	};

	Cause cause;

	explicit Exception(Cause cause) : cause(cause) { }

	const char *what() const throw() {
		switch (cause) {
			case BAD_INPUT: return "Error: bad input"; // not int && not operator
			case LOGIC_ERROR: return "Error: logic error"; // cannot give a result
			default: return "Unknown error";
		}
	}
};

class Calc {
private:
    std::stack<int> _st;
public:
    Calc();
    Calc(const Calc &other);
    explicit Calc(char *input);
    ~Calc();

    Calc &operator=(const Calc &other);

	enum Operation {
		ADD,
		SUB,
		DIV,
		MUL,
		NONE
	};

	bool parseNbr(std::istringstream &is);
	Operation parseOperator(std::istringstream &is);
	bool calculation(Operation op);
};

#endif // RPN_HPP
