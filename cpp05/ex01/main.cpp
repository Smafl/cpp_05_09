
#include "Bureaucrat.hpp"
#include "Form.hpp"
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

	Bureaucrat bob;
	std::cout << bob;
	Form form;
	form.beSigned(bob);
	bob.signForm(form);
	std::cout << form;
	return 0;
}
