
#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

Bureaucrat::Bureaucrat() :
	_name("Akakii Prokofievich"),
	_grade(150) { }

Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade) :
	_name(name) {
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) :
	_name(other._name),
	_grade(other._grade) { }

Bureaucrat::~Bureaucrat() { }

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		_grade = other._grade;
	}
	return *this;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::string Bureaucrat::getName() const {
	return _name;
}

unsigned int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade() {
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade() {
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b) {
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return o;
}
