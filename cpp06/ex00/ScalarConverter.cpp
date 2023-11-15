
#include "ScalarConverter.hpp"
#include <iostream>
#include <cctype>
#include <math.h> // isinf(), isnan()
#include <iomanip> // std::setprecision
#include <limits>

namespace {
enum Type {
	CHARACTER,
	INTEGER,
	FLOAT,
	DOUBLE,
	NONE,
	INF
};

Type getType(char *str) {
	std::string sstr(str);
	std::size_t dot_pos = sstr.find(".");
	std::size_t f_pos = sstr.find("f");
	char **endpnt = NULL;
	double dvalue = std::strtod(str, endpnt);
	if (std::strlen(str) == 1 && !std::isdigit(str[0]))
		return CHARACTER;
	else if (dvalue >= std::numeric_limits<int>::min() || dvalue <= std::numeric_limits<int>::max())
		return INTEGER;
	else if (dot_pos != std::string::npos && f_pos != std::string::npos)
		return FLOAT;
	// else if (isnan(dvalue)) // nanf
	// 	return NONE;
	// else if (isinf(dvalue))
	// 	return INF;
	// else if (dot_pos != std::string::npos)
	else
		return DOUBLE;
}

void printChar(char c) {
	if (std::isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void charConvert(char c) {
	printChar(c);
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void intConvert(char *str) {
	int ivalue(std::atoi(str));
	printChar(static_cast<char>(ivalue));
	std::cout << "int: " << ivalue << std::endl;
	std::cout << "float: " << static_cast<float>(ivalue) << std::endl;
	std::cout << "double: " << static_cast<double>(ivalue) << std::endl;
}

void floatConvert(char *str) {

}
}

// CONSTRUCTORS
ScalarConverter::ScalarConverter() { }

ScalarConverter::ScalarConverter(const ScalarConverter &) { }

// DESTRUCTOR
ScalarConverter::~ScalarConverter() { }

// ASSIGN OPERATOR
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) {
	return *this;
}

// CONVERTION
void ScalarConverter::convert(char *str) {
	Type t(getType(str));

	switch (t)
	{
	case CHARACTER:
		charConvert(str[0]);
		// std::cout << "char" << std::endl;
		break;
	case INTEGER:
		intConvert(str);
		// std::cout << "int" << std::endl;
		break;
	case FLOAT:
		floatConvert(str);
		// std::cout << "float" << std::endl;
		break;
	case DOUBLE:
		std::cout << "double" << std::endl;
		break;
	case NONE:
		std::cout << "nan" << std::endl;
		break;
	case INF:
		std::cout << "infinity" << std::endl;
		break;
	default:
		std::cout << "default" << std::endl;
		break;
	}
}
