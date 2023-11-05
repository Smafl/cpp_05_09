
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
	// try {
	// 	Bureaucrat hey;
	// 	std::cout << hey << std::endl;
	// 	hey.incrementGrade();
	// 	std::cout << hey << std::endl;
	// 	hey.decrementGrade();
	// 	std::cout << hey << std::endl;
	// } catch (const std::exception &e) {
	// 	std::cerr << e.what() << std::endl;
	// }

	// try {
	// 	Bureaucrat bob;
	// 	std::cout << bob;
	// 	ShrubberyCreationForm tree;
	// 	tree.beSigned(bob);
	// 	std::cout << tree;
	// } catch (const std::exception &e) {
	// 	std::cerr << e.what() << std::endl;
	// }

	// try {
	// 	Bureaucrat bob("Bob", 150);
	// 	ShrubberyCreationForm tree;
	// 	bob.signForm(tree);
	// 	// tree.execute(bob);
	// 	bob.executeForm(tree);
	// } catch (const std::exception &e) {
	// 	std::cerr << e.what() << std::endl;
	// }

	// try {
	// 	Bureaucrat bob("Bob", 72);
	// 	RobotomyRequestForm robo;
	// 	bob.signForm(robo);
	// 	robo.execute(bob);
	// 	// bob.executeForm(robo);
	// } catch (const std::exception &e) {
	// 	std::cerr << e.what() << std::endl;
	// }

	try {
		Bureaucrat bob("Bob", 5);
		PresidentialPardonForm pardon;
		bob.signForm(pardon);
		pardon.execute(bob);
		// bob.executeForm(pardon);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
