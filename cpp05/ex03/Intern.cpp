
#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) {
	(void)other;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &other) {
	(void)other;
	return *this;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
	std::string forms[3];
	forms[0] = "shrubbery creation";
	forms[1] = "robotomy request";
	forms[2] = "presidental pardon";

	for (int i = 0; i != 3; i++) {
		if (forms[i] == formName) {
			std::cout << "Intern creates " << forms[i] << " form." << std::endl;
			switch (i) {
				case 0:
					return new ShrubberyCreationForm(target);
				case 1:
					return new RobotomyRequestForm(target);
				case 2:
					return new PresidentialPardonForm(target);
				default:
					break;
			}
		}
	}
	std::cerr << "Such form cannot be created." << std::endl;
	return NULL;
}
