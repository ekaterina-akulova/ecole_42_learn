//
// Created by Екатерина Акулова on 28.10.2022.
//
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
        : Form(target, 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
{
	*this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
    if (this != &copy) {
        target = copy.target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(const Bureacrat &executor) const {
    if (this->getIsSign() == false)
        throw "The Form is not signed!";
    if (executor.getGrade() > this->getGradeExec())
        throw Bureacrat::GradeTooLowExeption();

    std::ofstream file;

    try {
        file.open(target + "_shrubbery");
    }
    catch (std::exception &exc) {
        std::cerr << exc.what() << std::endl;
    }
    if (file.is_open()) {
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
}