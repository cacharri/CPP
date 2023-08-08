/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:09:16 by ialvarez          #+#    #+#             */
/*   Updated: 2023/07/27 18:53:29 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructor por defecto
Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
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
