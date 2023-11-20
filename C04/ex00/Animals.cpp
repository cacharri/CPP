/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animals.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:05:59 by ialvarez          #+#    #+#             */
/*   Updated: 2023/11/20 19:10:20 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animals.hpp"

// Implementación de Animal

Animal::Animal() : type("Animal") {}

Animal::~Animal() {}

// Constructor de copia
Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "Copy constructor Animal called" << std::endl;
}

// Operador de asignación
Animal& Animal::operator=(const Animal& other) {
    std::cout << "Assignation operator of Animal called" << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

void Animal::makeSound() const {
    std::cout << "Animal makes a sound" << std::endl;
}

std::string Animal::getType() const {
    return type;
}

// Implementación de Dog

Dog::Dog() : Animal() {
    type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Copy constructor Dog called" << std::endl;
}

// Operador de asignación de Dog
Dog& Dog::operator=(const Dog& other) {
    std::cout << "Assignation operator of Dog called" << std::endl;
    Animal::operator=(other);
    return *this;
}

Dog::~Dog() {}


void Dog::makeSound() const {
    std::cout << "Guau guauu!!" << std::endl;
}

// Implementación de Cat

Cat::Cat() : Animal() {
    type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Copy constructor Cat called" << std::endl;
}

// Operador de asignación de Cat
Cat& Cat::operator=(const Cat& other) {
    std::cout << "Assignation operator of Cat called" << std::endl;
    Animal::operator=(other);
    return *this;
}

Cat::~Cat() {}

void Cat::makeSound() const {
    std::cout << "Miau miauu!" << std::endl;
}

// Implementación de WrongAnimal

WrongAnimal::WrongAnimal() : type("WrongAnimal") {}

WrongAnimal::~WrongAnimal() {}

// Constructor de copia
WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
    std::cout << "Copy constructor WrongAnimal called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "Assignation operator of WrongAnimal called" << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

void WrongAnimal::makeSound() const {
    std::cout << "Beeeee beeeeeee" << std::endl;
}

std::string WrongAnimal::getType() const {
    return type;
}

// Implementación de WrongCat

WrongCat::WrongCat() : WrongAnimal(){
    type = "WrongCat";
}

WrongCat::~WrongCat() {}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "Copy constructor of WrongCat called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "Assignation operator of WrongCat called" << std::endl;
    WrongAnimal::operator=(other);
    return *this;
}

void WrongCat::makeSoundCat() const {
    std::cout << "guaaa uaaaaaa" << std::endl;
}
