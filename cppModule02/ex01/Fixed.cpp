//
// Created by Екатерина Акулова on 13.10.2022.
//
#include "Fixed.hpp"

Fixed::Fixed() : fixedValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    this->fixedValue = value << fractionalBits;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    this->fixedValue = (int)roundf(value * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &copy) : fixedValue(copy.fixedValue) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &assign) {
    std::cout << "Copy assignment operator called" << std::endl;
    fixedValue = assign.getRawBits();
    return *this;
}

float	Fixed::toFloat( void ) const {
    return (float)fixedValue / (1 << fractionalBits);
}

int		Fixed::toInt( void ) const {
    //	cut of 8 right bits of full value
    return fixedValue >> fractionalBits;

}

int		Fixed::getRawBits( void ) const { return fixedValue; }

void	Fixed::setRawBits( int const raw ) { fixedValue = raw; }

std::ostream &operator<<(std::ostream &out, const Fixed &obj) {
    out << obj.toFloat();
    return out;
}
