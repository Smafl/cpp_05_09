
#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

class AForm {
private:
	const std::string _name;
	bool _isSigned;
	const unsigned int _gradeToSign;
	const unsigned int _gradeToExecute;
public:
	AForm();
	AForm(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExecute);
	AForm(const AForm &other);
	virtual ~AForm();

	AForm &operator=(const AForm &other);
	void swap(AForm &other);

	std::string getName() const;
	bool getIsSigned() const;
	unsigned int getGradeToSign() const;
	unsigned int getGradeToExecute() const;

	void beSigned(const Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const &executor) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, const AForm &f);

#endif // AFORM_HPP
