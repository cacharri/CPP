/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:31:53 by ialvarez          #+#    #+#             */
/*   Updated: 2023/09/06 17:40:50 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    ClapTrap::setHitPoints(100);
    ClapTrap::setEnergyPoints(100);
    ClapTrap::setAttackDamage(30);
    std::cout << "FragTrap [" << name << "] has been constructed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) {
    std::cout << "Copy constructor called" << std::endl;
	this->getName() = other.getName();
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap [" << ClapTrap::getName() << "] has been destroyed!" << std::endl;
}

void FragTrap::highFivesGuys(){
    std::cout << "Hey guys, give me a high five!!" << std::endl;
}

void FragTrap::attack(const std::string& target) {
    if (ClapTrap::getEnergyPoints() > 0) {
        std::cout << "[ScavTrap][" << FragTrap::getName() << "] attacks " << target << " with " << ClapTrap::getAttackDamage() << " points of damage!" << std::endl;
        ClapTrap::setEnergyPoints(getEnergyPoints() - 1);
    } else {
        std::cout << "[ScavTrap][" << FragTrap::getName() << "] can't attack " << target << ", out of energy!" << std::endl;
    }
}
