#include "PmergeMe.hpp"

bool isValidNumber(const std::string& str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: Please provide a sequence of positive integers." << std::endl;
        return 1;
    }

    try {
        std::vector<int> input;

        for (int i = 1; i < argc; ++i) {
            std::string arg(argv[i]);
            if (!isValidNumber(arg)) {
                throw std::invalid_argument("Error: Invalid input detected -> " + arg);
            }
            input.push_back(std::atoi(arg.c_str()));
        }

        PmergeMe sorter;
        sorter.processInput(input);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
