
#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

class Form {
private:
	const std::string _name;
	bool _isSigned;
	const unsigned int _gradeToSign;
	const unsigned int _gradeToExecute;
public:
	Form();
	Form(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExecute);
	Form(const Form &other);
	~Form();

	Form &operator=(const Form &other);

	std::string getName() const;
	bool getIsSigned() const;
	unsigned int getGradeToSign() const;
	unsigned int getGradeToExecute() const;

	void beSigned(const Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception {
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, const Form &f);

#endif // FORM_HPP
