#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        const WrongAnimal* wrongCat = new WrongCat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        std::cout << "WrongCat type: " << wrongCat->getType() << " " << std::endl << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        wrongCat->makeSound();
        meta->makeSound();
        delete wrongCat;
        delete i;
        delete j;
        delete meta;
        return 0;
}
