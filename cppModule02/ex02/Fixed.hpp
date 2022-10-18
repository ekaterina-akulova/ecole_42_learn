//
// Created by Екатерина Акулова on 16.10.2022.
//

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int value;
    static const int bit = 8;
public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed &copy);
    ~Fixed();

    Fixed	&operator=	(const Fixed &assign);

    bool	operator==	(const Fixed &object);
    bool	operator!=	(const Fixed &object);
    bool	operator<	(const Fixed &object);
    bool	operator>	(const Fixed &object);
    bool	operator<=	(const Fixed &object);
    bool	operator>=	(const Fixed &object);

    float	operator+	(const Fixed &summation);
    float	operator-	(const Fixed &subtracted);
    float	operator*	(const Fixed &multiplier);
    float	operator/	(const Fixed &devider);

    Fixed	operator++	();
    Fixed	operator--	();
    Fixed	operator++	(int);
    Fixed	operator--	(int);

    static Fixed		&min(Fixed &a, Fixed &b);
    static Fixed		&max(Fixed &a, Fixed &b);
    static const Fixed	&min(const Fixed &a, const Fixed &b);
    static const Fixed	&max(const Fixed &a, const Fixed &b);

    int		getRawBits	( void ) const;
    void	setRawBits	( int const raw );
    float	toFloat		( void ) const;
    int		toInt		( void ) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);

#endif