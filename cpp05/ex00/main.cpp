
#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
	// try {
	// 	Bureaucrat hey;
	// 	std::cout << hey << std::endl;
	// 	hey.incrementGrade();
	// 	std::cout << hey << std::endl;
	// 	hey.decrementGrade();
	// 	std::cout << hey << std::endl;
	// } catch (const std::exception &e) {
	// 	std::cerr << e.what() << std::endl;
	// }

	// try {
	// 	Bureaucrat bla("Bla", 1500);
	// 	std::cout << bla << std::endl;
	// 	bla.incrementGrade();
	// 	bla.decrementGrade();
	// 	std::cout << bla << std::endl;
	// } catch (const std::exception &e) {
	// 	std::cerr << e.what() << std::endl;
	// }

	try {
		Bureaucrat bla("Bob", -1);
		std::cout << bla << std::endl;
		bla.incrementGrade();
		bla.decrementGrade();
		std::cout << bla << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
