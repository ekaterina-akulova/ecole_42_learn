//
// Created by Екатерина Акулова on 12.10.2022.
//

#include "Fixed.hpp"

Fixed::Fixed() : fixedValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : fixedValue(other.fixedValue) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator= (const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    fixedValue = other.getRawBits();
    return *this;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return fixedValue;
}

void Fixed::setRawBits( int const raw ) {
    std::cout << "setRawBits member function called" << std::endl;
    fixedValue = raw;
}