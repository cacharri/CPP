/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:17:17 by ialvarez          #+#    #+#             */
/*   Updated: 2023/12/14 19:57:59 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {
    std::cout << "Default Constructor AMateria called" << std::endl;
}

AMateria::AMateria(std::string const & type) : material(type) {
    std::cout << "Constructor AMateria called" << std::endl;
}

AMateria::~AMateria() {
    std::cout << "Destructor AMateria called" << std::endl;
}

AMateria::AMateria(const AMateria& other) {
    *this = other;
    std::cout << "Copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
    this->material = other.getType();
	return *this;
	std::cout << "Assignation operator called" << std::endl;
}
/*
std::string	const & AMateria::getType() const {
		return this->material;
}*/