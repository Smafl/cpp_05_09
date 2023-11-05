
#ifndef PRESIDENTALPARDONFORM_HPP
#define PRESIDENTALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
	std::string _target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	~PresidentialPardonForm();

	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	void swap(PresidentialPardonForm &form);

	void execute(Bureaucrat const &executor) const;
};

#endif // PRESIDENTALPARDONFORM_HPP
