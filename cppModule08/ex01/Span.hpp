//
// Created by Екатерина Акулова on 09.11.2022.
//

#ifndef SPAN_HPP
#define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <cmath>

class Span {
private:
    unsigned int N;
    std::vector<int> arr;
public:
    Span();
    Span(unsigned int N);
    Span(const Span &obj);
    Span &operator=(const Span &obj);
    ~Span();

    unsigned int getN() const;
    std::vector<int> getArr() const;
    void showArr();

    void addNumber(int num);
    int shortestSpan();
    int longestSpan();

    class SpanIsFull : public std::exception {
    public:
        const char *what() const throw();
    };
    class NoSpace : public std::exception {
    public:
        const char *what() const throw();
    };

    void addNumber(std::vector<int>::iterator start,
                   std::vector<int>::iterator end);
};

#endif