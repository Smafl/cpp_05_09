
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
	try {
		Bureaucrat bob("Bob", 15);
		Intern intern;
		AForm *new_form;
		new_form = intern.makeForm("presidental pardon", bob.getName());
		new_form = intern.makeForm("shrubbery creation", bob.getName());
		new_form = intern.makeForm("robotomy request", bob.getName());
		// new_form = intern.makeForm("your pardon", bob.getName());
		if (new_form != NULL)
			bob.executeForm(*new_form);
		else
			std::cerr << "Such form does not exist." << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
