/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:17:17 by ialvarez          #+#    #+#             */
/*   Updated: 2024/02/21 19:30:44 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() {
    std::cout << "Default Constructor AMateria called" << std::endl;
}

AMateria::AMateria(std::string const & type) : material(type) {
    std::cout << "Constructor AMateria called" << std::endl;
}

AMateria::AMateria(const AMateria& other) {
    *this = other;
    std::cout << "Copy constructor called" << std::endl;
}

AMateria::~AMateria() {
    std::cout << "Destructor AMateria called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
    if (this != &other) {
        this->material = other.getType();
        std::cout << "Assignation operator called" << std::endl;
    }
    return *this;
}

std::string	const & AMateria::getType() const {
		return this->material;
}

AMateria* AMateria::clone() const {
    throw std::logic_error("El método clone() de AMateria es virtual puro y debe ser implementado en las clases derivadas.");
}

void AMateria::use(ICharacter& target) {
    std::cout << "Using materia on character: " << target.getName() << std::endl;
}

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& other) : AMateria(other) {}

Ice::~Ice() {}

AMateria* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& other) : AMateria(other) {}

Cure::~Cure() {}

AMateria* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
