
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
private:
	std::string	_name;
	unsigned int		_grade; // 1 is the highest, 150 is the lowest
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	~Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat &other);

	std::string getName() const;
	unsigned int getGrade() const;
	void incrementGrade();
	void decrementGrade();

	// void GradeTooHighException();
	// void GradeTooLowException();
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b);

#endif // BUREAUCRAT_HPP
