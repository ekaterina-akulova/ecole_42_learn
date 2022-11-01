//
// Created by Екатерина Акулова on 24.10.2022.
//

#ifndef WRONGAnimal_HPP
#define WRONGAnimal_HPP

#include <iostream>
class WrongAnimal {
protected:
    std::string type;
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &A_Animal);
    WrongAnimal &operator=(const WrongAnimal &A_Animal);
    virtual ~WrongAnimal();

    void makeSound() const;
    std::string getType() const;
};

#endif //WRONGAnimal_HPP
