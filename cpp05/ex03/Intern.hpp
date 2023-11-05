
#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <exception>

class Intern {
public:
	Intern();
	Intern(const Intern &other);
	~Intern();

	Intern &operator=(const Intern &other);

	AForm *makeForm(const std::string &formName, const std::string &target);

	class NonexistentForm : public std::exception {
	public:
		const char *what() const throw();
	};
};

#endif // INTERN_HPP
