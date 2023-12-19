/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:07:47 by ialvarez          #+#    #+#             */
/*   Updated: 2023/12/19 21:02:38 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : value(value << fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const double value) {
    // Redondeamos el valor de punto flotante al entero más cercano
    int32_t integerValue = static_cast<int32_t>(roundf(value * (1 << fractionalBits)));

    // Asignamos el valor de punto fijo
    this->value = integerValue;

    std::cout << "Double constructor called" << std::endl;
}

// Constructor que convierte un punto flotante constante en un valor de punto fijo
Fixed::Fixed(const float value) : value(roundf(value * (1 << fractionalBits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	this->value = other.value;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Assignation operator called" << std::endl;
	if (this != &other) {
		this->value = other.value;
	}
	return *this;
}

bool Fixed::operator>(const Fixed& other) const {
	return this->value > other.value;
}

bool Fixed::operator>=(const Fixed& other) const {
	return this->value >= other.value;
}

bool Fixed::operator!=(const Fixed& other) const {
	return this->value != other.value;
}

bool Fixed::operator<=(const Fixed& other) const {
	return this->value <= other.value;
}

bool Fixed::operator<(const Fixed& other) const {
	return this->value <= other.value;
}

bool Fixed::operator==(const Fixed& other) const{
	return this->value == other.value;
}

Fixed Fixed::operator+(const Fixed& other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
	++this->value;
	return (*this);
}
Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	tmp.value = this->value++;
	return (tmp);
}

Fixed& Fixed::operator--() {
	--this->value;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	tmp.value = this->value--;
	return (tmp);
}

// Sobrecarga de operadores: MIN y MAX

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return ((a < b) ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return ((a < b) ? b : a);
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

double Fixed::toDouble() const {
	return static_cast<double>(this->value) / (1 << fractionalBits);
}

int Fixed::getValue() const {
	return value;
}
int Fixed::setValue(int newValue) {
	Fixed::value = newValue;
	return newValue;
}

void	modifyValue(Fixed& fixed, int newValue) {
	fixed.setValue(newValue);
}

// Sobrecarga del operador << para imprimir el valor de punto fijo en el stream de salida
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;

}
Fixed Fixed::abs() const {
	return Fixed(std::abs(value)); // Suponiendo que value es el miembro interno que almacena el valor
}
