
#include "ScalarConverter.hpp"
#include <iostream>
#include <cctype>

namespace {
enum Type {
	CHARACTER,
	INTEGER,
	FLOAT,
	DOUBLE,
	NONE,
};

Type getType(const std::string &str) {
	size_t pos(str.find("."));
	double d;
	if (str.size() == 1 && !std::isdigit(str[0]))
		return CHARACTER;
	else if (pos != std::string::npos) {
		
	}

}
}

ScalarConverter::ScalarConverter() { }

ScalarConverter::ScalarConverter(const ScalarConverter &) { }

ScalarConverter::~ScalarConverter() { }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) {
	return *this;
}

void ScalarConverter::convert(const std::string &str) {
	Type t(getType(str));

	// convert it explicitly
	// display: char, int, float, double
}
