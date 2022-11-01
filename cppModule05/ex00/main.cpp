#include <iostream>
#include "Bureacrat.hpp"

int main() {

    Bureacrat a("Frog", 1);
    Bureacrat b("Cat", 150);
    Bureacrat d("Chicken", 151);
    Bureacrat c(b);
    std::cout << c.getName() << std::endl;
    std::cout << c.getGrade() << std::endl;
    a.increment_grade();
    b.decrement_grade();
    std::cout << a.getGrade() << std::endl;
    b.decrement_grade();
}
