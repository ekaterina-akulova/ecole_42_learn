//
// Created by Екатерина Акулова on 09.11.2022.
//

#include "Span.hpp"

Span::Span() : N(0) {}

Span::Span(unsigned int number) : N(number) {}

Span::Span(const Span &obj) {*this = obj;}

Span &Span::operator=(const Span &obj) {
    if (this == &obj)
        return (*this);
    N = obj.getN();
    arr = obj.getArr();
    return (*this);
}

Span::~Span() {}

unsigned int Span::getN() const {
    return (N);
}

std::vector<int> Span::getArr() const {
    return (arr);
}

void Span::showArr() {
    for (std::vector<int>::iterator it = arr.begin();
         it != arr.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void Span::addNumber(int num) {
    if (arr.size() >= N)
        throw Span::SpanIsFull();
    arr.push_back(num);
}

int Span::shortestSpan() {
    if (arr.size() <= 1)
        throw Span::NoSpace();
    int tmp_value = 0;
    int min_value = *std::min_element(arr.begin(), arr.end());
    for (unsigned int i = 1; i < arr.size(); ++i) {
        tmp_value = std::abs(arr[i] - arr[i - 1]);
        if (tmp_value < min_value)
            min_value = tmp_value;
    }
    return (min_value);
}

int Span::longestSpan() {
    if (arr.size() <= 1)
        throw Span::NoSpace();
    //	std::min_element returns an iterator,
    //	so we use *std::min_element to get the value
    int min = *std::min_element(arr.begin(), arr.end());
    int max = *std::max_element(arr.begin(), arr.end());
    return (max - min);
}

const char *Span::SpanIsFull::what() const throw() {
    return ("Error: Span is full!");
}

const char *Span::NoSpace::what() const throw() {
    return ("Error: Not enough elements!");
}

void Span::addNumber(std::vector<int>::iterator start,
                     std::vector<int>::iterator end) {
    if (end <= start)
        return;
    for (std::vector<int>::iterator it = start; it != end; ++it) {
        addNumber(*it);
    }
}