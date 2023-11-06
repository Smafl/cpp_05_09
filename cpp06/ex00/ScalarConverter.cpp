
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() { }

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	(void)other;
}

ScalarConverter::~ScalarConverter() { }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return *this;
}

void ScalarConverter::convert(const std::string &str) {
	// parse input, detect a type
	// convert it explicitly
	// display: char, int, float, double
}
