
#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <fstream>
#include <exception>

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("robotomy request form", 72, 45),
	_target("default") { }

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
	AForm("robotomy request form", 72, 45),
	_target(target) { }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
	AForm(other),
	_target(other._target) { }

RobotomyRequestForm::~RobotomyRequestForm() { }

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other) {
		RobotomyRequestForm new_form(other);
		swap(new_form);
	}
	return *this;
}

void RobotomyRequestForm::swap(RobotomyRequestForm &form) {
	AForm::swap(form);
	_target.swap(form._target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (!getIsSigned())
		return (void)(std::cerr << getName() << " cannot be executed because it is not signed." << std::endl);
	if (executor.getGrade() > getGradeToExecute()) {
		std::cerr << getName() << " cannot be executed because ";
		throw AForm::GradeTooLowException();
	}
	std::cout << "* some drilling noises *" << std::endl;
	std::cout << getName() << " has been robotomized successfully 50% of the time." << std::endl;
	std::cout << executor.getName() << " executed " << getName() << "." << std::endl;
}

std::ostream &operator<<(std::ostream &o, const RobotomyRequestForm &f) {
	o << "Name: " << f.getName() << ". ";
	if (f.getIsSigned())
		o << "Signed: yes. " << std::endl;
	else
		o << "Signed: no. " << std::endl;
	o << "Grade to sign: " << f.getGradeToSign() << ". Grade to execute: " << f.getGradeToExecute() << "." << std::endl;
	return o;
}
