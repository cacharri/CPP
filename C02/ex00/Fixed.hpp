/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:09:07 by ialvarez          #+#    #+#             */
/*   Updated: 2023/07/27 18:52:02 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed {
private:
    int value;  // Valor de punto entero
    static const int fractionalBits = 8; // Número de bits fraccionales (constante estática)

public:
    // Constructor por defecto
    Fixed();

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
};

#endif // FIXED_HPP
