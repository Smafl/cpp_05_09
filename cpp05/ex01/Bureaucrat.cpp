
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <exception>

Bureaucrat::Bureaucrat() :
	_name("Akakii Prokofievich"),
	_grade(150) { }

Bureaucrat::Bureaucrat(const std::string &name, int grade) :
	_name(name) {
	if (grade > 150) {
		std::cerr << "Cannot create a bureaucrat because ";
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade < 1) {
		std::cerr << "Cannot create a bureaucrat because ";
		throw Bureaucrat::GradeTooLowException();
	}
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) :
	_name(other._name),
	_grade(other._grade) { }

Bureaucrat::~Bureaucrat() { }

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		const_cast<std::string&>(_name) = other._name;
		_grade = other._grade;
	}
	return *this;
}

std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
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

void Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << "." << std::endl;
	} catch (const std::exception &e) {
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << "." << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b) {
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return o;
}
