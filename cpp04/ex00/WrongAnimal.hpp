//
// Created by Екатерина Акулова on 24.10.2022.
//

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
class WrongAnimal {
protected:
    std::string type;
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &animal);
    WrongAnimal &operator=(const WrongAnimal &animal);
    virtual ~WrongAnimal();

    void makeSound() const;
    std::string getType() const;
};

#endif //WRONGANIMAL_HPP
