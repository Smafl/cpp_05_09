
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
	try {
		Bureaucrat bob;
		std::cout << bob;
		Form form;
		form.beSigned(bob);
		bob.signForm(form);
		std::cout << form;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
