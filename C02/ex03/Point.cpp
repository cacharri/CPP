/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:08:23 by ialvarez          #+#    #+#             */
/*   Updated: 2024/04/11 19:17:04 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {
	std::cout << "Default constructor called" << std::endl;
}

Point::~Point() {
	std::cout << "Destructor called" << std::endl;
}

Point::Point(const Point& pointer) : x(pointer.x), y(pointer.y) {
    std::cout << "Copy constructor called" << std::endl;
}

Point::Point(const float i, const float j) : x(i), y(j) {
    std::cout << "Float constructor initialized" << std::endl;
}

Point& Point::operator=(const Point& pointer) {
	std::cout << "Assignation operator called" << std::endl;
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
