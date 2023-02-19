//
// Created by Екатерина Акулова on 10.11.2022.
//
#include "MutantStack.hpp"
#include <list>

void showArr(MutantStack<int>::iterator it_start,
             MutantStack<int>::iterator it_end) {
    for (MutantStack<int>::iterator it = it_start;
         it != it_end; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void showArr(std::list<int>::iterator it_start,
             std::list<int>::iterator it_end) {
    for (std::list<int>::iterator it = it_start;
         it != it_end; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main( void ) {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(5);
    mstack.push(97);
    mstack.push(67);
    mstack.pop();
    MutantStack<int>::iterator m_it_start = mstack.begin();
    MutantStack<int>::iterator m_it_end = mstack.end();
    showArr(m_it_start, m_it_end);
    ++m_it_start;
    --m_it_end;
    showArr(m_it_start, m_it_end);
    std::cout << "top mstack = " << mstack.top() << std::endl;
    std::cout << "size mstack = " << mstack.size() << std::endl;

    std::list<int> mlist;
    mlist.push_back(5);
    mlist.push_back(17);
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(97);
    mlist.push_back(67);
    mlist.pop_back();
    std::list<int>::iterator l_it_start = mlist.begin();
    std::list<int>::iterator l_it_end = mlist.end();
    showArr(l_it_start, l_it_end);
    ++l_it_start;
    --l_it_end;
    showArr(l_it_start, l_it_end);
    std::cout << "last mlist = " << mlist.back() << std::endl;
    std::cout << "size mlist = " << mlist.size() << std::endl;

    return 0;
}