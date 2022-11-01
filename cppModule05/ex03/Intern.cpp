//
// Created by Екатерина Акулова on 31.10.2022.
//
#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &intern) { (*this) = intern; }

Intern &Intern::operator=(const Intern &intern) {
    (void)intern;
    return *this;
}

Form *Intern::newPPF(std::string target) {
    return new PresidentialPardonForm(target);
}

Form *Intern::newRRF(std::string target) {
    return new RobotomyRequestForm(target);
}

Form *Intern::newSCF(std::string target) {
    return new ShrubberyCreationForm(target);
}

Form *Intern::makeForm(std::string name, std::string target) {
    std::string forms[] = {"PPF", "RRF", "SCF"};
    //	Making an array of function pointers:
    Form *(Intern::*func[])(std::string target) = {
        &Intern::newPPF,
                &Intern::newRRF,
                &Intern::newSCF
    };

    for (int i = 0; i < 3; i++) {
        if (name == forms[i])
            return (this->*func[i])(target);
    }
    std::cout << "Intern cannot create form " << name << std::endl;
    return NULL;
}