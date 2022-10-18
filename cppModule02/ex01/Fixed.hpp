//
// Created by Екатерина Акулова on 13.10.2022.
//

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int fixedValue;
    static const int fractionalBits = 8;
public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed &copy);
    ~Fixed();


    Fixed	&operator=(const Fixed &copy);

    int		getRawBits( void ) const;
    void	setRawBits( int const raw );
    float	toFloat( void ) const;
    int		toInt( void ) const;
};

//	<< operator
std::ostream &operator<<(std::ostream &out, const Fixed &obj);

#endif