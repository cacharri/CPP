#include <iostream>
#include "MutantStack.hpp"

int main() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl; // Debe imprimir 17
    mstack.pop();
    std::cout << mstack.size() << std::endl; // Debe imprimir 1
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack); // Copiar MutantStack a std::stack
    std::cout << s.top() << std::endl; // debería imprimir 0
    s.pop();
    std::cout << s.top() << std::endl;
    return 0;
}
