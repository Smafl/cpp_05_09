
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
	try {
		Bureaucrat hey;
		std::cout << hey << std::endl;
		hey.incrementGrade();
		std::cout << hey << std::endl;
		hey.decrementGrade();
		std::cout << hey << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	// try {
	// 	Bureaucrat bla("Bla", 1500);
	// 	std::cout << bla << std::endl;
	// 	bla.incrementGrade();
	// 	bla.decrementGrade();
	// 	std::cout << bla << std::endl;
	// } catch (const std::exception &e) {
	// 	std::cerr << e.what() << std::endl;
	// }

	// try {
	// 	Bureaucrat bla("Bob", -1);
	// 	std::cout << bla << std::endl;
	// 	bla.incrementGrade();
	// 	bla.decrementGrade();
	// 	std::cout << bla << std::endl;
	// } catch (const std::exception &e) {
	// 	std::cerr << e.what() << std::endl;
	// }

	// Bureaucrat a("Bob", -1);
	// Bureaucrat b;
	// b = a;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// Form form;
	// // try {
	// // 	form.beSigned(a);
	// // } catch (const std::exception &e) {
	// // 	std::cerr << e.what() << std::endl;
	// // }
	// // std::cout << form;
	// a.signForm(form);
	// Form form2("long and boring form", 1, 1);
	// // try {
	// // 	form2.beSigned(b);
	// // } catch (const std::exception &e) {
	// // 	std::cerr << e.what() << std::endl;
	// // }
	// a.signForm(form2);
	return 0;
}
