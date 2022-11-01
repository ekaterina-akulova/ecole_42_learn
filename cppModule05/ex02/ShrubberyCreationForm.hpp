//
// Created by Екатерина Акулова on 28.10.2022.
//

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

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

    void execute(const Bureacrat &executor) const;
};

#endif //SHRUBBERYCREATIONFORM_HPP
