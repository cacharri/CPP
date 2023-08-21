/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:08:23 by ialvarez          #+#    #+#             */
/*   Updated: 2023/08/21 21:16:07 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Constructor por defecto
Point::Point() : x(0), y(0) {
	std::cout << "Default constructor called" << std::endl;
}

// Destructor
Point::~Point() {
	std::cout << "Destructor called" << std::endl;
}

// Constructor de copia
Point::Point(const Point& pointer) {
	std::cout << "Copy constructor called" << std::endl;
}

Point::Point(const float i, const float j) : x(i), y(j) {
    std::cout << "Float constructor initialized" << std::endl;
}

// Sobrecarga del operador de asignación
Point& Point::operator=(const Point& pointer) {
	std::cout << "Assignation operator called" << std::endl;
	//Point tmp(*this);
	if (this != &pointer) {
		modifyValue(this->x, pointer.x.Fixed::getValue());
		this->y.Fixed::setValue(pointer.y.Fixed::getValue());
	}
	return *this;
}

Fixed Point::getValueX() const {
    return x;
}

Fixed Point::getValueY() const {
    return y;
}
