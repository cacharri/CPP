#include "PmergeMe.hpp"
#include <cstdlib>
#include <cctype>

bool isValidNumber(const char* str) {
    while (*str) {
        if (!isdigit(*str)) return false;
        str++;
    }
    return true;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: Please provide a sequence of positive integers." << std::endl;
        return 1;
    }

    std::vector<int> input;
    for (int i = 1; i < argc; ++i) {
        if (!isValidNumber(argv[i])) {
            std::cerr << "Error: Invalid input detected -> " << argv[i] << std::endl;
            return 1;
        }
        input.push_back(std::atoi(argv[i]));
    }

    PmergeMe sorter;
    sorter.processInput(input);

    return 0;
}
