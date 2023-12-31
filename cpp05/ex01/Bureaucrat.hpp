
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Form;

class Bureaucrat {
private:
	const std::string	_name; // const here is a subject requirement
	int					_grade; // 1 is the highest, 150 is the lowest
public:
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	~Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat &other);

	std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();

	void signForm(Form &form);

	class GradeTooHighException : public std::exception {
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b);

#endif // BUREAUCRAT_HPP

/*
An exception is an object of some class representing an exceptional occurrence.
Code that detects an error (often a library) throws an object.
A piece of code expresses desire to handle an exception by a catch clause.
The effect of a throw is to unwind the stack until a suitable catch is found
(in a function that directly or indirectly invoked the function that threw the exception).
*/
