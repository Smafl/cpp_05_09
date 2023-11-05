
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
#include <exception>

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("shrubbery creation form", 145, 137),
	_target("default") { }

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :
	AForm("shrubbery creation form", 145, 137),
	_target(target) { }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
	AForm(other),
	_target(other._target) { }

ShrubberyCreationForm::~ShrubberyCreationForm() { }

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other) {
		ShrubberyCreationForm new_form(other);
		swap(new_form);
	}
	return *this;
}

void ShrubberyCreationForm::swap(ShrubberyCreationForm &form) {
	AForm::swap(form);
	_target.swap(form._target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!getIsSigned())
		return (void)(std::cerr << getName() << " cannot be executed because it is not signed." << std::endl);
	if (executor.getGrade() > getGradeToExecute()) {
		std::cerr << getName() << " cannot be executed because ";
		throw AForm::GradeTooLowException();
	}
	std::string name = _target + "_shrubbery";
	std::ofstream outFile(name);
	if (!outFile.is_open())
		return (void)(std::cerr << "File cannot be opened." << std::endl);
	outFile << "                                                         .\n";
	outFile << "                                              .         ;  \n";
	outFile << "                 .              .              ;%     ;;   \n";
	outFile << "                   ,           ,                :;%  %;   \n";
	outFile << "                    :         ;                   :;%;'     .,   \n";
	outFile << "           ,.        %;     %;            ;        %;'    ,;\n";
	outFile << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n";
	outFile << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n";
	outFile << "               ;%;      %;        ;%;        % ;%;  ,%;'\n";
	outFile << "                `%;.     ;%;     %;'         `;%%;.%;'\n";
	outFile << "                 `:;%.    ;%%. %@;        %; ;@%;%'\n";
	outFile << "                    `:%;.  :;bd%;          %;@%;'\n";
	outFile << "                      `@%:.  :;%.         ;@@%;'   \n";
	outFile << "                        `@%.  `;@%.      ;@@%;         \n";
	outFile << "                          `@%%. `@%%    ;@@%;        \n";
	outFile << "                            ;@%. :@%%  %@@%;       \n";
	outFile << "                              %@bd%%%bd%%:;     \n";
	outFile << "                                #@%%%%%:;;\n";
	outFile << "                                %@@%%%::;\n";
	outFile << "                                %@@@%(o);  . '         \n";
	outFile << "                                %@@@o%;:(.,'         \n";
	outFile << "                            `.. %@@@o%::;         \n";
	outFile << "                               `)@@@o%::;         \n";
	outFile << "                                %@@(o)::;        \n";
	outFile << "                               .%@@@@%::;         \n";
	outFile << "                               ;%@@@@%::;.          \n";
	outFile << "                              ;%@@@@%%:;;;. \n";
	outFile << "                          ...;%@@@@@%%:;;;;,..\n";
	std::cout << executor.getName() << " executed " << getName() << "." << std::endl;
}

std::ostream &operator<<(std::ostream &o, const ShrubberyCreationForm &f) {
	o << "Name: " << f.getName() << ". ";
	if (f.getIsSigned())
		o << "Signed: yes. " << std::endl;
	else
		o << "Signed: no. " << std::endl;
	o << "Grade to sign: " << f.getGradeToSign() << ". Grade to execute: " << f.getGradeToExecute() << "." << std::endl;
	return o;
}
