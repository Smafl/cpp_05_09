
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
	ERR
};

Type getType(char *str) {
	std::string sstr(str);
	std::size_t dot_pos = sstr.find(".");
	std::size_t f_pos = sstr.find("f");
	char **endpnt = NULL;
	double dvalue = std::strtod(str, endpnt);
	if (std::strlen(str) == 1 && !std::isdigit(str[0]))
		return CHARACTER;
	else if (dot_pos != std::string::npos && f_pos != std::string::npos)
		return FLOAT;
	else if (dot_pos != std::string::npos)
		return DOUBLE;
	else if (isnan(dvalue) || isinf(dvalue))
		return NONE;
	else if (dvalue >= std::numeric_limits<int>::min() || dvalue <= std::numeric_limits<int>::max())
		return INTEGER;
	return ERR;
}

void printNone() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void printChar(char c) {
	if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void charConvert(char c) {
	printChar(c);
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void intConvert(char *str) {
	int ivalue(std::atoi(str));
	printChar(static_cast<char>(ivalue));
	std::cout << "int: " << ivalue << std::endl;
	std::cout << "float: " << static_cast<float>(ivalue) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(ivalue) << std::endl;
}

void floatConvert(char *str) {
	char **endpnt = NULL;
	double dvalue = std::strtod(str, endpnt);
	printChar(static_cast<char>(dvalue));
	std::cout << "int: " << static_cast<int>(dvalue) << std::endl;
	std::cout << "float: " << static_cast<float>(dvalue) << "f" << std::endl;
	std::cout << "double: " << dvalue << std::endl;
}

void doubleConvert(char *str) {
	char **endpnt = NULL;
	double dvalue = std::strtod(str, endpnt);
	printChar(static_cast<char>(dvalue));
	std::cout << "int: " << static_cast<int>(dvalue) << std::endl;
	std::cout << "float: " << static_cast<float>(dvalue) << "f" << std::endl;
	std::cout << "double: " << dvalue << std::endl;
}
}

// CONVERTION
void ScalarConverter::convert(char *str) {
	Type t(getType(str));

	switch (t)
	{
	case CHARACTER:
		std::cout << "char" << std::endl;
		charConvert(str[0]);
		break;
	case INTEGER:
		std::cout << "int" << std::endl;
		intConvert(str);
		break;
	case FLOAT:
		std::cout << "float" << std::endl;
		floatConvert(str);
		break;
	case DOUBLE:
		std::cout << "double" << std::endl;
		doubleConvert(str);
		break;
	case NONE:
		std::cout << "nan" << std::endl;
		printNone();
		break;
	case ERR:
		std::cout << "err" << std::endl;
		break;
	default:
		std::cout << "default" << std::endl;
		break;
	}
}
