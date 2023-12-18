/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animals.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:33:27 by ialvarez          #+#    #+#             */
/*   Updated: 2023/11/28 18:33:30 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animals.hpp"

// Implementación de Animal

Animal::Animal() : type("Animal") {
    std::cout << "Constructor Animal called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Destructor Animal called" << std::endl;
}

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

Dog::Dog() : Animal(), brain(new Brain) {
    type = "Dog";
    std::cout << "Constructor Dog called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain) {
    std::cout << "Copy constructor Dog called" << std::endl;
}

// Operador de asignación de Dog
Dog& Dog::operator=(const Dog& other) {
    std::cout << "Assignation operator of Dog called" << std::endl;
    Animal::operator=(other);
    return *this;
}

Dog::~Dog() {
    std::cout << "Destructor Dog called" << std::endl;
}


void Dog::makeSound() const {
    std::cout << "Guau guauu!!" << std::endl;
}

// Implementación de Cat

Cat::Cat() : Animal(), brain(new Brain) {
    type = "Cat";
    std::cout << "Constructor Cat called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain) {
    std::cout << "Copy constructor Cat called" << std::endl;
}

// Operador de asignación de Cat
Cat& Cat::operator=(const Cat& other) {
    std::cout << "Assignation operator of Cat called" << std::endl;
    Animal::operator=(other);
    return *this;
}

Cat::~Cat() {
    std::cout << "Destructor Cat called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Miau miauu!" << std::endl;
}

// Implementación de WrongAnimal

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "Constructor WrongAnimal called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "Destructor WrongAnimal called" << std::endl;
}

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
    std::cout << "WrongAnimal makes a sound" << std::endl;
}

std::string WrongAnimal::getType() const {
    return type;
}

// Implementación de WrongCat

WrongCat::WrongCat() : WrongAnimal(){
    type = "WrongCat";
    std::cout << "Constructor WrongCat called" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "Destructor WrongCat called" << std::endl;
}

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
// Implementación de Brain

Brain::Brain() {
    std::cout << "Constructor Brain called" << std::endl;
}


Brain::~Brain() {
    std::cout << "Destructor Brain called" << std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << "Copy constructor of Brain copied" << std::endl;
    for (int i = 0; i < 100; i++)
    {
        ideas[i] = other.ideas[i];
    }
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "Assignation operator of Brain called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; ++i) {
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}
