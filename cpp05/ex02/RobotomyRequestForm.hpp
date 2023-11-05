
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
	std::string _target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	~RobotomyRequestForm();

	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	void swap(RobotomyRequestForm &form);

	void execute(Bureaucrat const &executor) const;
};

#endif // ROBOTOMYREQUESTFORM_HPP
