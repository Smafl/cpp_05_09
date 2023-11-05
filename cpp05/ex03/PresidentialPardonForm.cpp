
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <fstream>
#include <exception>

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("presidental pardon form", 25, 5),
	_target("default") { }

PresidentialPardonForm::PresidentialPardonForm(const std::string target) :
	AForm("presidental pardon form", 25, 5),
	_target(target) { }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :
	AForm(other),
	_target(other._target) { }

PresidentialPardonForm::~PresidentialPardonForm() { }

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other) {
		PresidentialPardonForm new_form(other);
		swap(new_form);
	}
	return *this;
}

void PresidentialPardonForm::swap(PresidentialPardonForm &form) {
	AForm::swap(form);
	_target.swap(form._target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (!getIsSigned())
		return (void)(std::cerr << getName() << " cannot be executed because it is not signed." << std::endl);
	if (executor.getGrade() > getGradeToExecute()) {
		std::cerr << getName() << " cannot be executed because ";
		throw AForm::GradeTooLowException();
	}
	std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	std::cout << executor.getName() << " executed " << getName() << "." << std::endl;
}

std::ostream &operator<<(std::ostream &o, const PresidentialPardonForm &f) {
	o << "Name: " << f.getName() << ". ";
	if (f.getIsSigned())
		o << "Signed: yes. " << std::endl;
	else
		o << "Signed: no. " << std::endl;
	o << "Grade to sign: " << f.getGradeToSign() << ". Grade to execute: " << f.getGradeToExecute() << "." << std::endl;
	return o;
}
