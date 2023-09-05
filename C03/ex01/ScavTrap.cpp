/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:14:32 by ialvarez          #+#    #+#             */
/*   Updated: 2023/09/05 22:42:26 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    ClapTrap::setHitPoints(100);
    ClapTrap::setEnergyPoints(50);
    ClapTrap::setAttackDamage(20);
    std::cout << "ScavTrap [" << name << "] has been constructed!" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap [" << ScavTrap::getName() << "] has been destroyed!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap [" << ScavTrap::getName() << "] is now in Gatekeeper mode!" << std::endl;
}
	
void ScavTrap::attack(const std::string& target) {
    if (ClapTrap::getEnergyPoints() > 0) {
        std::cout << "[ScavTrap][" << ScavTrap::getName() << "] attacks " << target << " with " << ClapTrap::getAttackDamage() << " points of damage!" << std::endl;
        ClapTrap::setEnergyPoints(getEnergyPoints() - 1);
    } else {
        std::cout << "[ScavTrap][" << ScavTrap::getName() << "] can't attack " << target << ", out of energy!" << std::endl;
    }
}
