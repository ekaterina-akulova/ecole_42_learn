//
// Created by Екатерина Акулова on 12.10.2022.
//

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int fixedValue;
    static const int bit = 8;
public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed &other);
    Fixed &operator= (const Fixed &other);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

#endif //FIXED_H
