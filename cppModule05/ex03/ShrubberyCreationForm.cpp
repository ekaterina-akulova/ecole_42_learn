//
// Created by Екатерина Акулова on 31.10.2022.
//
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
        : Form(target, 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
        : Form(copy), target(copy.target)
{
//	*this = copy;	//	not necessary
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
    if (this != &copy) {
        target = copy.target;
    }
    return *this;
}

//void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
    if (this->getSign() == false)
        throw "The Form is not signed!";
    if (executor.getGrade() > this->getGradeExec())
        throw Bureaucrat::GradeTooLowException();

    std::ofstream file;

    try {
        file.open(target + "_shrubbery");
    }
    catch (std::exception &exc) {
        std::cerr << exc.what() << std::endl;
    }

    file
            << "                                                         .       " << std::endl
            << "                                              .         ;        " << std::endl
            << "                 .              .              ;%     ;;         " << std::endl
            << "                   ,           ,                :;%  %;          " << std::endl
            << "                    :         ;                   :;%;'     .,   " << std::endl
            << "           ,.        %;     %;            ;        %;'    ,;     " << std::endl
            << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'      " << std::endl
            << "              %;       %;%;      ,  ;       %;  ;%;   ,%;'       " << std::endl
            << "               ;%;      %;        ;%;        % ;%;  ,%;'         " << std::endl
            << "                `%;.     ;%;     %;'         `;%%;.%;'           " << std::endl
            << "                 `:;%.    ;%%. %@;        %; ;@%;%'              " << std::endl
            << "                    `:%;.  :;bd%;          %;@%;'                " << std::endl
            << "                      `@%:.  :;%.         ;@@%;'                 " << std::endl
            << "                        `@%.  `;@%.      ;@@%;                   " << std::endl
            << "                          `@%%. `@%%    ;@@%;                    " << std::endl
            << "                            ;@%. :@%%  %@@%;                     " << std::endl
            << "                              %@bd%%%bd%%:;                      " << std::endl
            << "                                #@%%%%%:;;                       " << std::endl
            << "                                %@@%%%::;                        " << std::endl
            << "                                %@@@%(o);  . '                   " << std::endl
            << "                                %@@@o%;:(.,'                     " << std::endl
            << "                            `.. %@@@o%::;                        " << std::endl
            << "                               `)@@@o%::;                        " << std::endl
            << "                                %@@(o)::;                        " << std::endl
            << "                               .%@@@@%::;                        " << std::endl
            << "                               ;%@@@@%::;.                       " << std::endl
            << "                              ;%@@@@%%:;;;.                      " << std::endl
            << "                          ...;%@@@@@%%:;;;;,..                   " << std::endl;
    file.close();
}