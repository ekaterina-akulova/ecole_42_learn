//
// Created by Екатерина Акулова on 24.10.2022.
//

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
public:
    Cat();
    Cat(const Cat &cat);
    Cat &operator=(const Cat &cat);
     ~Cat();

    virtual void makeSound() const;
    void set_idea(int i, const std::string &idea);
    const std::string &get_idea(int i) const;

private:
    Brain *brain;
};

#endif