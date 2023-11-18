
#include "ScalarConverter.hpp"
#include <iostream>
#include <cctype>
#include <math.h> // isinf(), isnan()
#include <iomanip> // std::setprecision
#include <limits>
#include <cfloat> // DBL_MAX and DBL_MIN
#include <cerrno> // errno

namespace {
enum Type {
	CHARACTER,
	INTEGER,
	FLOAT,
	DOUBLE,
	OVER,
	ERROR
};

bool isFloat(double dvalue) {

	if (isnan(dvalue) || isinf(dvalue))
		return true;
	if ((dvalue >= std::numeric_limits<float>::min() || dvalue <= std::numeric_limits<float>::max())) {
		return true;
	}
	return false;
}

bool isInt(double dvalue, std::size_t dot_pos) {
	if (dot_pos == std::string::npos &&
		(dvalue >= std::numeric_limits<int>::min() && dvalue <= std::numeric_limits<int>::max()))
		return true;
	return false;
}

Type getType(char *str) {
	std::size_t len = std::strlen(str);
	if (len == 1 && !std::isdigit(str[0]))
		return CHARACTER;
	errno = 0;
	char *endpnt = NULL;
	double dvalue = std::strtod(str, &endpnt);
	if (errno != 0)
		return OVER;
	std::string sstr(str);
	std::size_t dot_pos = sstr.find(".");
	if (*endpnt == '\0') {
		if (isInt(dvalue, dot_pos))
			return INTEGER;
		else if (isnan(dvalue) || isinf(dvalue))
			return DOUBLE;
		else if (dot_pos == std::string::npos)
			return ERROR;
		else
			return DOUBLE;
	}
	else if (isFloat(dvalue) && (*endpnt == 'f' && static_cast<std::size_t>((endpnt - str)) == len - 1))
		return FLOAT;
	return ERROR;
}

void printChar(double dvalue) {
	if (dvalue >= std::numeric_limits<char>::min() && dvalue <= std::numeric_limits<char>::max()) {
		if (std::isprint(static_cast<char>(dvalue)))
			std::cout << "char: '" << static_cast<char>(dvalue) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
}

void charConvert(char c) {
	if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(c) << std::endl;
}

void intConvert(char *str) {
	char *endpnt = NULL;
	double dvalue = std::strtod(str, &endpnt);
	printChar(dvalue);
	std::cout << "int: " << static_cast<int>(dvalue) << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(dvalue) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(dvalue) << std::endl;
}

void floatConvert(char *str) {
	char *endpnt = NULL;
	double dvalue = std::strtod(str, &endpnt);
	printChar(dvalue);
	if (dvalue >= std::numeric_limits<int>::min() && dvalue <= std::numeric_limits<int>::max())
		std::cout << "int: " << static_cast<int>(dvalue) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(dvalue) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << dvalue << std::endl;
}

void doubleConvert(char *str) {
	char *endpnt = NULL;
	double dvalue = std::strtod(str, &endpnt);
	printChar(dvalue);
	if (dvalue >= std::numeric_limits<int>::min() && dvalue <= std::numeric_limits<int>::max())
		std::cout << "int: " << static_cast<int>(dvalue) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	if (dvalue >= std::numeric_limits<float>::min() || dvalue <= std::numeric_limits<float>::max())
		std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(dvalue) << "f" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << dvalue << std::endl;
}
}

void printError() {
	std::cout << "impossible to detect a type" << std::endl;
	std::cout << "input examples:" << std::endl;
	std::cout << "for char: c, a, ..." << std::endl;
	std::cout << "for int: 0, -42, 42, ..." << std::endl;
	std::cout << "for float: 0.0f, -4.2f, 4.2f, ..." << std::endl;
	std::cout << "for double: 0.0, -4.2, 4.2, ..." << std::endl;
}

// CONVERTION
void ScalarConverter::convert(char *str) {
	Type t(getType(str));

	switch (t)
	{
	case CHARACTER:
		charConvert(str[0]);
		break;
	case INTEGER:
		intConvert(str);
		break;
	case FLOAT:
		floatConvert(str);
		break;
	case DOUBLE:
		doubleConvert(str);
		break;
	case OVER:
		std::cout << "out of range" << std::endl;
		break;
	case ERROR:
		printError();
		break;
	}
}
