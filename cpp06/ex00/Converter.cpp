
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
	NONE,
	POSINF,
	NEGINF,
	OVER,
	ERROR
};

// Type getType(char *str) {
// 	std::size_t len = std::strlen(str);
// 	std::string sstr(str);
// 	std::size_t dot_pos = sstr.find(".");

// 	if (len == 1 && !std::isdigit(str[0]))
// 		return CHARACTER;

// 	errno = 0;
// 	char *endpnt = NULL;
// 	double dvalue = std::strtod(str, &endpnt);
// 	if (errno != 0)
// 		return OVER;
// 	// std::cout << errno << std::endl;
// 	if (*endpnt == '\0') {
// 		if (dvalue == DBL_MAX)
// 			return POSINF;
// 		else if (dvalue == -DBL_MAX)
// 			return NEGINF;
// 		else if (isinf(dvalue)) {
// 			if (sstr.find("-") != std::string::npos)
// 				return NEGINF;
// 			return POSINF;
// 		}
// 		else if (isnan(dvalue))
// 			return NONE;
// 		else if ((dvalue >= std::numeric_limits<int>::min() || dvalue <= std::numeric_limits<int>::max()) &&
// 				dot_pos == std::string::npos)
// 			return INTEGER;
// 		else if (dvalue == 0.0 && str != endpnt) {
// 			return ERROR;
// 		}
// 		else
// 			return DOUBLE;
// 	}
// 	else if (str[len - 1] == 'f' && dot_pos != std::string::npos &&
// 		(dvalue >= std::numeric_limits<float>::min() || dvalue <= std::numeric_limits<float>::max()))
// 		return FLOAT;
// 	return ERROR;
// }

bool isFloat(double dvalue) {

	if (isnan(dvalue) || isinf(dvalue))
		return true;
	if ((dvalue >= std::numeric_limits<float>::min() || dvalue <= std::numeric_limits<float>::max())) {
		return true;
	}
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
		if (dot_pos == std::string::npos &&
			(dvalue >= std::numeric_limits<int>::min() || dvalue <= std::numeric_limits<int>::max()))
			return INTEGER;
		else if (isnan(dvalue) || isinf(dvalue))
			return DOUBLE;
		else
			return DOUBLE;
	}
	else if (isFloat(dvalue) && (*endpnt == 'f' && str[len - 1] == 'f'))
		return FLOAT;
	return ERROR;
}

void printPseudo(std::string str) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << str << "f" << std::endl;
	std::cout << "double: " << str << std::endl;
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
	std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(c) << std::endl;
}

void intConvert(char *str) {
	int ivalue(std::atoi(str));
	printChar(static_cast<char>(ivalue));
	std::cout << "int: " << ivalue << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(ivalue) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(ivalue) << std::endl;
}

void floatConvert(char *str) {
	char *endpnt = NULL;
	double dvalue = std::strtod(str, &endpnt);
	printChar(static_cast<char>(dvalue));
	std::cout << "int: " << static_cast<int>(dvalue) << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(dvalue) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << dvalue << std::endl;
}

void doubleConvert(char *str) {
	char *endpnt = NULL;
	double dvalue = std::strtod(str, &endpnt);
	printChar(static_cast<char>(dvalue));
	std::cout << "int: " << static_cast<int>(dvalue) << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(dvalue) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << dvalue << std::endl;
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
	case OVER:
		std::cout << "out of range" << std::endl;
		break;
	case ERROR:
		std::cout << "impossible to detect a type" << std::endl;
		break;
	}
}

// todo:
// redo all convert function and
// check nan, +/-inf there
