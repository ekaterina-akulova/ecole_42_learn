#include <iostream>
#include "Convert.hpp"

int main(int argc, char **argv) {
    if (argc == 2)
        {
            Convert conv(argv[1]);
            conv.print();
        }
    else
        std::cout << "Wrong number of arguments" << std::endl;
}
