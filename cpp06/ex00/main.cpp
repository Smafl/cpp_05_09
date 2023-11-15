
#include "ScalarConverter.hpp"
#include <iostream>

// #define ASSERT(b) if (!(b)) { printf("Error at line %d\n", __LINE__); return 1; }

// int convert_char() {
// 	;
// }

// int convert_int() {
// 	;
// }

// int convert_float() {
// 	;
// }

// int convert_double() {
// 	;
// }

// int main()
// {
// 	int	n_tests_failed;

// 	n_tests_failed = 0;
// 	n_tests_failed += convert_char();

// 	if (n_tests_failed == 0)
// 	{
// 		printf("Nice!\n");
// 	}
// 	else
// 	{
// 		printf("Number of failed tests: %d\n", n_tests_failed);
// 	}
// 	return (n_tests_failed);
// }

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Expected input: ./convert <literal>" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}
