#include "Span.hpp"

int main() {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    try {
        std::cout << sp.shortestSpan() << std::endl;  // debe mostrar 2
        std::cout << sp.longestSpan() << std::endl;   // debe mostrar 14
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    //Prueba 10000 números
    Span bigSpan(10000);

    std::vector<int> numbers;
    std::srand(std::time(NULL));
    for (int i = 0; i < 10000; ++i)
        numbers.push_back(std::rand());

    try {
        bigSpan.addNumbers(numbers.begin(), numbers.end());
        std::cout << "Shortest Span (10k numbers): " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest Span (10k numbers): " << bigSpan.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

