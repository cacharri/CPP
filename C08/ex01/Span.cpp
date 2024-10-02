#include "Span.hpp"

Span::Span(unsigned int n) : _maxSize(n) {}

Span::~Span() {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}
void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw std::overflow_error("Maximum size reached");
    }
    _numbers.push_back(number);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to calculate span");
    }

    std::vector<int> sortedNumbers = _numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    int shortest = INT_MAX;
    for (size_t i = 1; i < sortedNumbers.size(); ++i) {
        int span = sortedNumbers[i] - sortedNumbers[i - 1];
        if (span < shortest) {
            shortest = span;
        }
    }
    return shortest;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to calculate span");
    }
    
    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    
    return max - min;
}
