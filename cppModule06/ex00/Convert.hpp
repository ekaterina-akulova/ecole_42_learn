//
// Created by Екатерина Акулова on 01.11.2022.
//

#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <string>
#include <iomanip>
class Convert
{
private:
    std::string str;
public:
    Convert();
    Convert(std::string _str);
    Convert(const Convert &convert);
    ~Convert();

    Convert &operator=(const Convert &convert);
    std::string getString () const;

    void	printChar() const;
    void	printInt() const;
    void	printFloat() const;
    void	printDouble() const;
    void    print() const;
};


#endif //CONVERT_HPP
