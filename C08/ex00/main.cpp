#include "easyfind.hpp"

int main() {
    // Prueba con std::vector
    std::vector<int> vec;
    for (int i = 1; i <= 5; ++i) {
        vec.push_back(i);
    }

    try {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Value found in vector: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        easyfind(vec, 10);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    //std::list
    std::list<int> lst;
    for (int i = 1; i <= 5; ++i) {
        lst.push_back(i);
    }

    try {
        std::list<int>::iterator it = easyfind(lst, 8);
        std::cout << "Value found in list: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        easyfind(lst, 42);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
