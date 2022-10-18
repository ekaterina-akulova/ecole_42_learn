//
// Created by Екатерина Акулова on 16.10.2022.
//

#include "Fixed.hpp"

Fixed::Fixed() : value(0) {}

Fixed::Fixed(const int value): value(value << bit) {}

Fixed::Fixed(const float value): value((int)roundf(value * (1 << bit))) {}

Fixed::Fixed(const Fixed &copy): value(copy.value) {}

Fixed:: ~Fixed() {}

Fixed &Fixed::operator=(const Fixed &assign) {
    value = assign.getRawBits();
    return *this;
}

float	Fixed::toFloat ( void ) const { return (float)value / (1 << bit); }

int		Fixed::toInt ( void ) const { return value >> bit; }

int		Fixed::getRawBits ( void ) const { return value; }

void	Fixed::setRawBits ( int const raw ) { value = raw; }

bool    Fixed::operator==   (const Fixed &object) {
    return this->getRawBits() == object.getRawBits();
}

bool    Fixed::operator!=   (const Fixed &object) {
    return this->getRawBits() != object.getRawBits();
}

bool    Fixed::operator<    (const Fixed &object) {
    return this->getRawBits() < object.getRawBits();
}

bool    Fixed::operator>    (const Fixed &object) {
    return this->getRawBits() > object.getRawBits();
}

bool    Fixed::operator<=   (const Fixed &object) {
    return this->getRawBits() <= object.getRawBits();
}

bool    Fixed::operator>=   (const Fixed &object) {
    return this->getRawBits() >= object.getRawBits();
}

float    Fixed::operator+    (const Fixed &summation) {
    return this->toFloat() + summation.toFloat();
}

float    Fixed::operator-    (const Fixed &summation) {
    return this->toFloat() - summation.toFloat();
}

float    Fixed::operator*    (const Fixed &summation) {
    return this->toFloat() * summation.toFloat();
}

float    Fixed::operator/    (const Fixed &summation) {
    return this->toFloat() / summation.toFloat();
}

Fixed    Fixed::operator++    (void) {
    this->value++;
    return *this;
}

Fixed    Fixed::operator--    (void) {
    this->value--;
    return *this;
}
 Fixed Fixed::operator++    (int) {
    Fixed prev(*this);
    ++(*this);
    return prev;
}

Fixed    Fixed::operator--    (int) {
    Fixed prev(*this);
    --(*this);
    return prev;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a.getRawBits() < b.getRawBits()) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a.getRawBits() > b.getRawBits()) ? a : b;
}

std::ostream &operator<<	(std::ostream &out, const Fixed &obj) {
    out << obj.toFloat();
    return out;
}
