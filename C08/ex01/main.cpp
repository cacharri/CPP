#include "Span.hpp"

int main() {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    try {
        std::cout << sp.shortestSpan() << std::endl; // Debe imprimir 2
        std::cout << sp.longestSpan() << std::endl;  // Debe imprimir 14
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::vector<int> numbers;
    for (int i = 1; i <= 5; ++i) {
        numbers.push_back(i);
    }
    
    try {
        sp.addNumbers(numbers.begin(), numbers.end());
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
