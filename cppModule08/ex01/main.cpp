//
// Created by Екатерина Акулова on 09.11.2022.
//
#include <vector>
#include "Span.hpp"

int main() {
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    try {
        Span ar1(4);
        std::vector<int> lst;
        for (int i = 1; i <= 4; i++)
            lst.push_back(i + 10);
        for (std::vector<int>::iterator it = lst.begin();
             it != lst.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        ar1.addNumber(lst.begin(), lst.end());
        ar1.showArr();
        std::cout << "Shortest Span: " << ar1.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << ar1.longestSpan() << std::endl;
    }
    catch (std::exception &exc) {
        std::cout << exc.what() << std::endl;
    }
    std::cout << "---My test (10 000 element)---" << std::endl;
    try {
        std::srand(time(0));
        Span span(10000);

        for (int i = 0; i < 10000; i++)
            span.addNumber(rand());
//		span.showArr();
        std::cout << "Longest Span: "  << span.longestSpan()  << std::endl;
        std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;
    }
    catch (std::exception &exc) {
        std::cout << exc.what() << std::endl;
    }
}