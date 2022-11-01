#include "Bureacrat.hpp"
#include "Form.hpp"
#include "Exeption.hpp"

int main()
{
    Form form("Cert", 10, 4);
    Bureacrat john("John", 11);
    Bureacrat Phillip("Phillip", 0);
    Form form2("Form2", 151, 4);

    std::cout << form << std::endl << std::endl;
    std::cout << john << std::endl;

    john.signForm(form);
    john.increment_grade();
    john.signForm(form);

    std::cout << std::endl << form << std::endl;

    return 0;
}
