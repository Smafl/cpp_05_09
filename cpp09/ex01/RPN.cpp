
#include "RPN.hpp"
#include <sstream>

Calc::Calc() { }

Calc::Calc(char *input) {
    std::istringstream is(input);
        int nbr;
        char operation;
    while (is.good()) {
        ;
    }
}

Calc::~Calc() { }

void Calc::push(int nbr) {
	_st.push(nbr);
}

void Calc::pop() {
	if (_st.empty())
		throw Exception(Exception::EMPTY_STACK);
	_st.pop();
}

int Calc::top() const {
	return _st.top();
}

void Calc::printStack() const {
	std::size_t size = _st.size();
	
	for (std::stack<int>::container_type::iterator it = _st.c.begin();)
}
