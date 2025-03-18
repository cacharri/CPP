#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <limits.h>
#include <ctime>


class Span {
    public:
        Span();
        ~Span();
        Span(const Span& other);
        Span& operator=(const Span& other);
        Span(unsigned int n);
        void addNumber(int number);
        template <typename Iterator>
        void addNumbers(Iterator begin, Iterator end);
        int shortestSpan() const;
        int longestSpan() const;

    private:
        unsigned int _maxSize;
        std::vector<int> _numbers;
};

template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end) {
    while (begin != end) {
        addNumber(*begin);
        ++begin;
    }
}

#endif
