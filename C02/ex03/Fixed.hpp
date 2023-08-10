/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:08:10 by ialvarez          #+#    #+#             */
/*   Updated: 2023/08/10 19:28:34 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <limits>

class Fixed {
private:
	int value;  // Valor de punto entero
	static const int fractionalBits = 8; // Número de bits fraccionales (constante estática)

public:
	// Constructor por defecto
	Fixed();

	// Constructor que convierte un entero constante en un valor de punto fijo
	Fixed(const int value);

	// Constructor que convierte un punto flotante constante en un valor de punto fijo
	Fixed(const float value);

	// Destructor
	~Fixed();

	// Constructor de copia
	Fixed(const Fixed& other);

	// Sobrecarga del operador de asignación, 6 nuevos
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

	Fixed&	operator++();		// Operador de preincremento (++valor)
	Fixed	operator++(int);	// Operador de postincremento (valor++)
	Fixed&	operator--();		// Operador de predecremento (--valor)
	Fixed	operator--(int);	// Operador de postdecremento (valor--)

	// Sobrecarga de operadores: MIN y MAX

	static const Fixed& min(const Fixed& a, const Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);

	// Función miembro para obtener el valor bruto del valor de punto fijo
	int getRawBits() const;

	// Función miembro para establecer el valor bruto del valor de punto fijo
	void setRawBits(int const raw);

	// Función miembro que convierte el valor de punto fijo a un valor de punto flotante
	float toFloat() const;

	// Función miembro que convierte el valor de punto fijo a un valor entero
	int toInt() const;

	int getValue() const;
	int setValue(int newValue); 
};

void	modifyValue(Fixed& fixed, int newValue);

// Sobrecarga del operador << para imprimir el valor de punto fijo en el stream de salida
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif // FIXED_HPP
