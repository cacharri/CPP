/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:01:12 by ialvarez          #+#    #+#             */
/*   Updated: 2023/12/19 20:57:49 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <limits>	

class Fixed {
private:
	int value;
	static const int fractionalBits = 8;

public:

	Fixed();

	Fixed(const int value);

	Fixed(const float value);

	~Fixed();

	Fixed(const Fixed& other);

	Fixed& operator=(const Fixed& other);

	// Sobrecarga del operador de comparación
	
	bool    operator>(const Fixed& other) const;
	bool    operator>=(const Fixed& other) const;
	bool    operator<(const Fixed& other) const;
	bool    operator<=(const Fixed& other) const;
	bool    operator==(const Fixed& other) const;
	bool	operator!=(const Fixed& other) const;

	// Sobrecarga del operador aritmético
	
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

	// Operadores de incremento y decremento

	Fixed&	operator++();
	Fixed	operator++(int);
	Fixed&	operator--();
	Fixed	operator--(int);

	static const Fixed& min_cons(const Fixed& a, const Fixed& b);
	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& max_cons(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);

	// Función miembro para obtener el valor bruto del valor de punto fijo
	int getRawBits() const;

	// Función miembro para establecer el valor bruto del valor de punto fijo
	void setRawBits(int const raw);

	// Función miembro que convierte el valor de punto fijo a un valor de punto flotante
	float toFloat() const;

	// Función miembro que convierte el valor de punto fijo a un valor entero
	int toInt() const;
};

// Sobrecarga del operador << para imprimir el valor de punto fijo en el stream de salida
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
