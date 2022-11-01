//
// Created by Екатерина Акулова on 31.10.2022.
//

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include <fstream>

class ShrubberyCreationForm : public Form
{
private:
    std::string target;
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &copy);
    ShrubberyCreationForm & operator= (const ShrubberyCreationForm &copy);

//	void execute(Bureaucrat const &executor) const;
    void execute(const Bureaucrat &executor) const;
};

#endif