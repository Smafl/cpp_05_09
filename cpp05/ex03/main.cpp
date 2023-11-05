
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
	Bureaucrat bob("Bob", 15);
	Intern intern;
	intern.makeForm("presidental pardon", bob.getName());
	intern.makeForm("shrubbery creation", bob.getName());
	intern.makeForm("robotomy request", bob.getName());
	intern.makeForm("your pardon", bob.getName());
	return 0;
}
