//
// Created by Екатерина Акулова on 31.10.2022.
//
#include "Intern.hpp"

int main()
{
    Bureaucrat	barin("Barin", 40);	//	80, 60, 40

    Intern	intern;

    Form	*f1 = intern.makeForm("smth", "sweet");	//	This form can't be done
    delete f1;	//	not necessary because of f1 = NULL;

    Form	*f2 = intern.makeForm("RRF", "Bender");	//	Intern makes new robotomy form
    std::cout << *f2 << std::endl;			//	check if the form is really exist

    barin.signForm(*f2);
    try {
        f2->execute(barin);
    }
    catch (const char *str) {
        std::cerr	<< barin.getName() << " couldn’t execute " << f2->getName()
                     << " because " << str << std::endl;
    }
    catch (const std::exception &exc) {
        std::cerr << exc.what() << std::endl;
    }
    delete f2;	//	do not forget to free memory
    return 0;
}