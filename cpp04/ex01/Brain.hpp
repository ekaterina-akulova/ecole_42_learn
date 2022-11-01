//
// Created by Екатерина Акулова on 24.10.2022.
//

#ifndef BRAIN_HPP
#define BRAIN_HPP


# include <iostream>
# include <string>

class Brain {
public:
	Brain();
	Brain(const Brain &brain);
	Brain &operator=(const Brain &brain);
	~Brain();
    std::string &operator[](int i);
    void set_idea(int i, const std::string &idea);
    const std::string &get_idea(int i) const;
    static const int max_num = 2;
private:
    std::string ideas[max_num];
};

#endif
