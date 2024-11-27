#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <cctype>

class RPN {
public:
    RPN(); // Constructor
    ~RPN(); // Destructor

    int evaluate(const std::string& expression); // Evalúa la expresión en notación polaca inversa
};

#endif
