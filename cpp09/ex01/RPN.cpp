
#include "RPN.hpp"
#include <sstream>

Calc::Calc() { }

Calc::Calc(char *input) {
    std::istringstream is(input);
	enum Calc::Operation op;
    while (is.good()) {
		if (!parseNbr(is)) {
			op = parseOperator(is);
			if (op == NONE)
				throw Exception(Exception::BAD_INPUT);
			else {
				if (!calculation(op))
					throw Exception(Exception::LOGIC_ERROR);
			}
		}
	}
	if (is.fail() && !is.eof())
		throw Exception(Exception::BAD_INPUT);

//	check and print result
	if (_st.empty())
		throw Exception(Exception::LOGIC_ERROR);
	int result = _st.top();
	_st.pop();
	if (!_st.empty())
		throw Exception(Exception::LOGIC_ERROR);
	else
		std::cout << "Result: " << result << std::endl;
}

Calc::Calc(const Calc &other) :
	_st(other._st) { }

Calc::~Calc() { }

Calc &Calc::operator=(const Calc &other) {
	if (this != &other) {
		Calc newObj(other);
		newObj._st = other._st;;
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
		is.clear();
		is.seekg(position);
		return false;
	}
	_st.push(nbr);
	is.ignore();
	return true;
}

Calc::Operation Calc::parseOperator(std::istringstream &is) {
	char c;
	std::streampos position = is.tellg();
	is >> c;
	if (is.fail()) {
		is.clear();
		is.seekg(position);
		return Calc::NONE;
	}
	is.ignore();
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
