/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 19:17:45 by ialvarez          #+#    #+#             */
/*   Updated: 2023/07/27 21:32:38 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

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

    // Sobrecarga del operador de asignación
    Fixed& operator=(const Fixed& other);

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

#endif // FIXED_HPP
