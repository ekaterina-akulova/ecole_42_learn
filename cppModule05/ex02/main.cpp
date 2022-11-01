#include "Form.hpp"
#include "Exeption.hpp"
#include "Bureacrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try {
        Bureacrat barin("Peter", 55);    //	15, 55, 140
        std::cout << barin << std::endl;
        std::cout << std::endl;

        ShrubberyCreationForm scf("SCF");
		std::cout << scf << std::endl;
        RobotomyRequestForm rrf("RRF");
		std::cout << rrf << std::endl;
        PresidentialPardonForm ppf("PPF");
		std::cout << ppf << std::endl;
		std::cout << std::endl;


          std::cout << scf << std::endl;
          barin.signForm(scf);
          std::cout << scf << std::endl;
          barin.executeForm(scf);
          scf.execute(barin);
          std::cout << std::endl;


          std::cout << rrf << std::endl;
         barin.signForm(rrf);
         std::cout << rrf << std::endl;
         barin.executeForm(rrf);
         std::cout << std::endl;


         std::cout << ppf << std::endl;
        barin.signForm(ppf);
        std::cout << ppf << std::endl;
        barin.executeForm(ppf);
        std::cout << std::endl;
    }
    catch (std::exception &exc) {
        std::cerr << exc.what() << std::endl;
    }
    return 0;
}
