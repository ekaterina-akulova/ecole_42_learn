//
// Created by Екатерина Акулова on 01.11.2022.
//

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
class Base
{
public:
    virtual ~Base();
};
class A : public Base
{

};

class B : public Base
{

};

class C : public Base
{

};

Base * generate(void);
void identify(Base *p);
void identify(Base &p);
#endif //BASE_HPP
