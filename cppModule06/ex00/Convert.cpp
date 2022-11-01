//
// Created by Екатерина Акулова on 01.11.2022.
//
#include "Convert.hpp"

Convert::Convert() : str(" ") {}

Convert::Convert(std::string _str) : str(_str) {}

Convert::Convert(const Convert &convert) { *this = convert; }

Convert &Convert::operator=(const Convert &x) {
    return (*this = x);
}

Convert::~Convert() {}

std::string Convert::getString() const { return (this->str); }

void  Convert::printChar() const {
    try {
        if (str.length() == 1 && !std::isdigit(str[0]))
            std::cout << str << std::endl;
        else  if (std::stoi(str) < CHAR_MIN || std::stoi(str) > CHAR_MAX)
            std::cout << "impossible" << std::endl;
        else if (std::stoi(str) < 33 || std::stoi(str) > 126)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << static_cast<char>(std::stoi(str)) << std::endl;
    }
    catch (...) {
        std::cout << "impossible" << std::endl;
    }
}

void  Convert::printInt() const {
    try {
         if (str.length() == 1 && !std::isdigit(str[0]))
             std:: cout << static_cast<int>(str[0]) << std::endl;
         else
            std::cout << stoi(str)  << std::endl;
    }
    catch (...) {
        std::cout << "impossible" << std::endl;
    }
}

void  Convert::printFloat() const {
    try {
        if (str.length() == 1 && !std::isdigit(str[0]))
            std::cout << std::fixed << std::setprecision(1) << static_cast<float>(str[0]) << "f"<< std::endl;
        else
            std::cout << std::fixed << std::setprecision(1)  << static_cast<double> (stof(str)) << "f" << std::endl;
    }
    catch (...) {
        std::cout << "impossible" << std::endl;
    }
}

void  Convert::printDouble() const {
    try {
        if (str.length() == 1 && !std::isdigit(str[0]))
            std::cout << std::fixed << std::setprecision(1) << static_cast<double>(str[0]) << std::endl;
        else
            std::cout << std::fixed << std::setprecision(1)  << static_cast<double> (stod(str)) << std::endl;
    }
    catch (...) {
        std::cout << "impossible" << std::endl;
    }
}

void  Convert::print() const
{
    printChar();
    printInt();
    printFloat();
    printDouble();
}