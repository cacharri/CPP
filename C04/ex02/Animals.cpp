/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animals.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:33:27 by ialvarez          #+#    #+#             */
/*   Updated: 2024/02/21 16:45:32 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animals.hpp"

AAnimal::AAnimal() : type("AAnimal") {
    std::cout << "Constructor AAnimal called" << std::endl;
}

AAnimal::~AAnimal() {
    std::cout << "Destructor AAnimal called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type) {
    std::cout << "Copy constructor AAnimal called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    std::cout << "Assignation operator of AAnimal called" << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

void AAnimal::makeSound() const {
    std::cout << "AAnimal makes a sound" << std::endl;
}

std::string AAnimal::getType() const {
    return type;
}

Dog::Dog() : AAnimal(), brain(new Brain) {
    type = "Dog";
    std::cout << "Constructor Dog called" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other), brain(new Brain) {
    std::cout << "Copy constructor Dog called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Assignation operator of Dog called" << std::endl;
    AAnimal::operator=(other);
    return *this;
}

Dog::~Dog() {
    std::cout << "Destructor Dog called" << std::endl;
    delete brain;
}

void Dog::makeSound() const {
    std::cout << "Guau guauu!!" << std::endl;
}

Cat::Cat() : AAnimal(), brain(new Brain) {
    type = "Cat";
    std::cout << "Constructor Cat called" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other), brain(new Brain) {
    std::cout << "Copy constructor Cat called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Assignation operator of Cat called" << std::endl;
    AAnimal::operator=(other);
    return *this;
}

Cat::~Cat() {
    std::cout << "Destructor Cat called" << std::endl;
    delete brain;
}

void Cat::makeSound() const {
    std::cout << "Miau miauu!" << std::endl;
}

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "Constructor WrongAnimal called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "Destructor WrongAnimal called" << std::endl;
}

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
