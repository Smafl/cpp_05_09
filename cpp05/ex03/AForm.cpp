
#include "AForm.hpp"
#include <iostream>
#include <exception>

AForm::AForm() :
	_name("routine form"),
	_isSigned(false),
	_gradeToSign(150),
	_gradeToExecute(100) { }

AForm::AForm(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExecute) :
	_name(name),
	_isSigned(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute) {
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) :
	_name(other._name),
	_isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute) { }

AForm::~AForm() { }

AForm &AForm::operator=(const AForm &other) {
	if (this != &other) {
		const_cast<std::string&>(_name) = other._name;
		_isSigned = other._isSigned;
		const_cast<unsigned int&>(_gradeToSign) = other._gradeToSign;
		const_cast<unsigned int&>(_gradeToExecute) = other._gradeToExecute;
	}
	return *this;
}

void AForm::swap(AForm &other) {
	const_cast<std::string&>(_name).swap(const_cast<std::string&>(other._name));
	std::swap(_isSigned, other._isSigned);
	std::swap(const_cast<unsigned int&>(_gradeToSign), const_cast<unsigned int&>(other._gradeToSign));
	std::swap(const_cast<unsigned int&>(_gradeToExecute), const_cast<unsigned int&>(other._gradeToExecute));
}

std::string AForm::getName() const {
	return _name;
}

bool AForm::getIsSigned() const {
	return _isSigned;
}

unsigned int AForm::getGradeToSign() const {
	return _gradeToSign;
}

unsigned int AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign) {
		std::cerr << _name << " cannot signed because ";	
		throw AForm::GradeTooLowException();
	}
	_isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "grade is too low";
}

std::ostream &operator<<(std::ostream &o, const AForm &f) {
	o << "Name: " << f.getName() << ". ";
	if (f.getIsSigned())
		o << "Signed: yes. " << std::endl;
	else
		o << "Signed: no. " << std::endl;
	o << "Grade to sign: " << f.getGradeToSign() << ". Grade to execute: " << f.getGradeToExecute() << "." << std::endl;
	return o;
}
