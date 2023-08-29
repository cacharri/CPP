/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:25:51 by ialvarez          #+#    #+#             */
/*   Updated: 2023/08/29 19:37:54 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& initialName) : Name(initialName), Hit_points(10), Energy_points(10), Attack_damage(0) {
	std::cout << "Constructor for Name called" << std::endl;
}

std::string	ClapTrap::getName() const {
		return Name;
		}

// Destructor
ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

//Si NO hay (ENERGY_POINTS) or (HIT_POINTS) NO puede hacer NADA 
// Al atacar causa que pierda <attack damage> en Hit_points. USO: (1) ENERGY 
void ClapTrap::attack(const std::string& target) {
	if (ClapTrap::Energy_points > 0 && ClapTrap::Hit_points > 0){
		std::cout << "ClapTrap " << ClapTrap::Name << " attacks " << target << ", causing " << ClapTrap::Attack_damage << " points of damage!" << std::endl;
		ClapTrap::Energy_points--;
		ClapTrap::takeDamage(ClapTrap::Attack_damage);
	}
	else
		std::cout << "ClapTrap " << ClapTrap::Name << " can´t attacks " << target << std::endl;
}

// Al repararse recupera <amount> de vida en Hit_points. USO:  (1) ENERGY
void ClapTrap::beRepaired(unsigned int amount){
	if (ClapTrap::Energy_points > 0) {
		std::cout << "ClapTrap " << ClapTrap::Name << " repaired himself " << amount << " points" << std::endl;
		ClapTrap::Hit_points += amount;
		ClapTrap::Energy_points--;
	}
	else
		std::cout << "ClapTrap " << ClapTrap::Name << " can´t be repaired because doesn´t have Hit Points" << std::endl;
}


void ClapTrap::takeDamage(unsigned int amount) {
    if (ClapTrap::Hit_points > 0) {
        unsigned int actualDamage = (amount > ClapTrap::Hit_points) ? ClapTrap::Hit_points : amount;
        ClapTrap::Hit_points -= actualDamage;
        std::cout << "ClapTrap " << Name << " takes " << actualDamage << " points of damage!" << std::endl;
    }
}
