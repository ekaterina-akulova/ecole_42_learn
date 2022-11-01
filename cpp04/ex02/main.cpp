//
// Created by Екатерина Акулова on 25.10.2022.
//
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


int main() {
    A_Animal *arr[10];
    //A_Animal a; //error

    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0)
            arr[i] = new Dog;
        else
            arr[i] = new Cat;
    }
    std::cout << std::endl;

    for (int i = 0; i < 10; i++)
        delete arr[i];
    std::cout << std::endl;

    Dog dog;
    Cat cat;
    Dog dog2;
    Cat cat2(cat);

    dog2 = dog;

    dog2.set_idea(0, "another idea!!");
    cat2.set_idea(0, "another idea!!");

    std::cout << dog.get_idea(0) << std::endl;
    std::cout << cat.get_idea(0) << std::endl;
    std::cout << dog2.get_idea(0) << std::endl;
    std::cout << cat2.get_idea(0) << std::endl;
    std::cout << std::endl;

}