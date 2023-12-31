
#include "Form.hpp"
#include <iostream>
#include <exception>

Form::Form() :
	_name("routine form"),
	_isSigned(false),
	_gradeToSign(15),
	_gradeToExecute(100) { }

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) :
	_name(name),
	_isSigned(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute) {
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other) :
	_name(other._name),
	_isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute) { }

Form::~Form() { }

Form &Form::operator=(const Form &other) {
	if (this != &other) {
		const_cast<std::string&>(_name) = other._name;
		_isSigned = other._isSigned;
		const_cast<int&>(_gradeToSign) = other._gradeToSign;
		const_cast<int&>(_gradeToExecute) = other._gradeToExecute;
	}
	return *this;
}

std::string Form::getName() const {
	return _name;
}

bool Form::getIsSigned() const {
	return _isSigned;
}

int Form::getGradeToSign() const {
	return _gradeToSign;
}

int Form::getGradeToExecute() const {
	return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign) {
		std::cerr << getName() << " cannot be signed because ";
		throw Form::GradeTooLowException();
	}
	_isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "grade is too low";
}

std::ostream &operator<<(std::ostream &o, const Form &f) {
	o << "Name: " << f.getName() << ". ";
	if (f.getIsSigned())
		o << "Signed: yes. " << std::endl;
	else
		o << "Signed: no. " << std::endl;
	o << "Grade to sign: " << f.getGradeToSign() << ". Grade to execute: " << f.getGradeToExecute() << "." << std::endl;
	return o;
}
