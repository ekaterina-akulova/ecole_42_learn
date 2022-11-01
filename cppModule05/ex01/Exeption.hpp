//
// Created by Екатерина Акулова on 28.10.2022.
//

#ifndef EXEPTION_HPP
#define EXEPTION_HPP

#include <iostream>

class Exeption
{
protected:
    int num;
    std::string str;
public:
    Exeption();
    ~Exeption();

    virtual void display () = 0;
};

#endif //EXEPTION_HPP
