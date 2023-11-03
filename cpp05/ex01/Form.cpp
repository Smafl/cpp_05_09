
#include "Form.hpp"
#include <iostream>
#include <exception>

Form::Form() :
	_name("routine form"),
	_isSigned(false),
	_gradeToSign(150),
	_gradeToExecute(100) { }

Form::Form(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExecute) :
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
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

std::string Form::getName() const {
	return _name;
}

bool Form::getIsSigned() const {
	return _isSigned;
}

unsigned int Form::getGradeToSign() const {
	return _gradeToSign;
}

unsigned int Form::getGradeToExecute() const {
	return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() >= _gradeToSign)
		throw Form::GradeTooLowException();
	_isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade is too low";
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
