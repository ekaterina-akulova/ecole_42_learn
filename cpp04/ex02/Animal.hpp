//
// Created by Екатерина Акулова on 24.10.2022.
//

#ifndef Animal_HPP
# define Animal_HPP

# include <iostream>

class  A_Animal {
protected:
    std::string type;
public:
    A_Animal();
    A_Animal(const A_Animal &A_Animal);
    A_Animal &operator=(const A_Animal &A_Animal);
    virtual ~A_Animal();

    virtual void makeSound() const = 0;
    std::string getType() const;
};

#endif