/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animals.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:05:59 by ialvarez          #+#    #+#             */
/*   Updated: 2023/09/19 19:22:52 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animals.hpp"

// Implementación de Animal

Animal::Animal() : type("Animal") {}

Animal::~Animal() {}

void Animal::makeSound() const {
    std::cout << "Animal makes a sound" << std::endl;
}

std::string Animal::getType() const {
    return type;
}

// Implementación de Dog

Dog::Dog() {
    type = "Dog";
}

Dog::~Dog() {}

void Dog::makeSound() const {
    std::cout << "Guau guauu!!" << std::endl;
}

// Implementación de Cat

Cat::Cat() {
    type = "Cat";
}

Cat::~Cat() {}

void Cat::makeSound() const {
    std::cout << "Miau miauu!" << std::endl;
}

// Implementación de WrongAnimal

WrongAnimal::WrongAnimal() : type("WrongAnimal") {}

WrongAnimal::~WrongAnimal() {}

void WrongAnimal::makeSound() const {
    std::cout << "Beeeee beeeeeee" << std::endl;
}

std::string WrongAnimal::getType() const {
    return type;
}

// Implementación de WrongCat

WrongCat::WrongCat() {}

WrongCat::~WrongCat() {}
