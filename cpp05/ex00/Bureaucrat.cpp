
#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() :
	_name("Akakii Prokofievich"),
	_grade(150) { }

Bureaucrat::Bureaucrat(const Bureaucrat &other) :
	_name(other._name),
	_grade(other._grade) { }

Bureaucrat::~Bureaucrat() { }

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		_name = other._name;
		_grade = other._grade;
	}
	return *this;
}

std::string Bureaucrat::getName() const {
	return _name;
}

unsigned int Bureaucrat::getGrade() const {
	return _grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	std::cout << "Grade is too high" << std::endl;
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	std::cout << "Grade is too low" << std::endl;
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b) {
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return o;
}
