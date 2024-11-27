#include "RPN.hpp"

// Constructor
RPN::RPN() {}

// Destructor
RPN::~RPN() {}

// Función para evaluar una expresión en notación polaca inversa
int RPN::evaluate(const std::string& expression) {
    std::stack<int> stack; // Usamos una pila para procesar la expresión
    std::istringstream stream(expression); // Tokenizamos la expresión
    std::string token;

    while (stream >> token) {
        if (std::isdigit(token[0]) && token.size() == 1) { // Si es un número entre 0 y 9
            stack.push(token[0] - '0'); // Convertimos el carácter a número y lo añadimos a la pila
        } else if (token == "+" || token == "-" || token == "*" || token == "/") { // Si es un operador
            if (stack.size() < 2) {
                throw std::runtime_error("Error: Invalid expression (not enough operands).");
            }
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();

            if (token == "+") stack.push(a + b);
            else if (token == "-") stack.push(a - b);
            else if (token == "*") stack.push(a * b);
            else if (token == "/") {
                if (b == 0) throw std::runtime_error("Error: Division by zero.");
                stack.push(a / b);
            }
        } else {
            throw std::runtime_error("Error: Invalid token in expression.");
        }
    }

    if (stack.size() != 1) {
        throw std::runtime_error("Error: Invalid expression (too many operands).");
    }

    return stack.top(); // El resultado final está en la cima de la pila
}
