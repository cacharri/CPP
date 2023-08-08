/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:32:11 by ialvarez          #+#    #+#             */
/*   Updated: 2023/07/27 21:32:43 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructor por defecto
Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Constructor que convierte un entero constante en un valor de punto fijo
Fixed::Fixed(const int value) : value(value << fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
}

// Constructor que convierte un punto flotante constante en un valor de punto fijo
Fixed::Fixed(const float value) : value(roundf(value * (1 << fractionalBits))) {
    std::cout << "Float constructor called" << std::endl;
}

// Destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Constructor de copia
Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    this->value = other.value;
}

// Sobrecarga del operador de asignación
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Assignation operator called" << std::endl;
    if (this != &other) {
        this->value = other.value;
    }
    return *this;
}

// Función miembro para obtener el valor bruto del valor de punto fijo
int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

// Función miembro para establecer el valor bruto del valor de punto fijo
void Fixed::setRawBits(int const raw) {
    this->value = raw;
}

// Función miembro que convierte el valor de punto fijo a un valor de punto flotante
float Fixed::toFloat() const {
    return static_cast<float>(this->value) / (1 << fractionalBits);
}

// Función miembro que convierte el valor de punto fijo a un valor entero
int Fixed::toInt() const {
    return this->value >> fractionalBits;
}

// Sobrecarga del operador << para imprimir el valor de punto fijo en el stream de salida
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}
