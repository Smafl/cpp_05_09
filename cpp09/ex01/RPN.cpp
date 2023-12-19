
#include "RPN.hpp"
#include <sstream>

Calc::Calc() { }

Calc::Calc(char *input) {
    std::istringstream is(input);
	enum Calc::Operation op;
    while (is.good()) {
		if (!parseNbr(is)) {
			// std::cout << "not a nbr\n"; // delete
			op = parseOperator(is);
			if (op == NONE) {
				// std::cout << "not an operator\n"; // delete
				throw Exception(Exception::BAD_INPUT);
			}
			else {
				if (!calculation(op)) {
					std::cout << "can't calculate" << std::endl; // delete
					throw Exception(Exception::LOGIC_ERROR);
				}
			}
		}
	}
	if (is.fail() && !is.eof())
		throw Exception(Exception::BAD_INPUT);

	if (_st.empty()) {
		std::cout << "no result" << std::endl; // delete
		throw Exception(Exception::LOGIC_ERROR);
	}
	int result = _st.top();
	_st.pop();
	if (!_st.empty()) {
		std::cout << "ambigious result" << std::endl; // delete
		throw Exception(Exception::LOGIC_ERROR);
	}
	else
		std::cout << "Result: " << result << std::endl;
}

Calc::Calc(const Calc &other) :
	_st(other._st) { }

Calc::~Calc() { }

Calc &Calc::operator=(const Calc &other) {
	if (this != &other) {
		Calc newObj(other);
		newObj._st.swap(_st);
	}
	return *this;
}

bool Calc::calculation(Operation op) {
	if (_st.empty())
		return false;
	int second = _st.top();
	_st.pop();
	if (_st.empty())
		return false;
	int first = _st.top();
	_st.pop();
	int result;

	switch (op) {
		case ADD:
			result = first + second;
			break;
		case SUB:
			result = first - second;
			break;
		case MUL:
			result = first * second;
			break;
		case DIV:
			if (second == 0)
				return false;
			result = first / second;
			break;
		default: return false;
	}
	_st.push(result);
	return true;
}

bool Calc::parseNbr(std::istringstream &is) {
	int nbr;
	std::streampos position = is.tellg();
	is >> nbr;
	if (is.fail()) {
	// if (!is.good()) {
		is.clear();
		is.seekg(position);
		return false;
	}
	// std::cout << nbr << std::endl;
	_st.push(nbr);
	is.ignore();
	return true;
}

Calc::Operation Calc::parseOperator(std::istringstream &is) {
	char c;
	std::streampos position = is.tellg();
	is >> c;
	if (is.fail()) {
	// if (!is.good()) {
		is.clear();
		is.seekg(position);
		return Calc::NONE;
	}
	is.ignore();
	// std::cout << c << std::endl;
	switch (c) {
		case '+':
			return Calc::ADD;
		case '-':
			return Calc::SUB;
		case '/':
			return Calc::DIV;
		case '*':
			return Calc::MUL;
		default:
			return Calc::NONE;
	}
	return Calc::NONE;
}

void Calc::printStack() const {
	std::stack<int> copystack(_st);

	while (!copystack.empty()) {
		std::cout << copystack.top() << std::endl;
		copystack.pop();
	}
}
