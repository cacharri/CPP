#include <iostream>
#include "Iter.hpp"

void printInt(int x) {
    std::cout << x << " ";
}

void incrementInt(int &x) {
    ++x;
}

template <typename T>
void print(const T &x) {
    std::cout << x << " ";
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    std::cout << "Array original: ";
    iter(arr, 5, printInt); // Imprime el array original
    std::cout << std::endl;

    iter(arr, 5, incrementInt); // Incrementa cada elemento
    std::cout << "Array incrementado: ";
    iter(arr, 5, printInt); // Imprime el array incrementado
    std::cout << std::endl;

    std::string strArr[] = {"Hello", "World", "C++", "Templates"};
    std::cout << "Array de strings: ";
    iter(strArr, 4, print<std::string>); // Imprime el array de strings
    std::cout << std::endl;

    return 0;
}
