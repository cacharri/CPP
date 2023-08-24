/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:25:51 by ialvarez          #+#    #+#             */
/*   Updated: 2023/08/24 20:29:03 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& initialName) : Name(initialName) {
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
    std::string attack_damage;
}

// Al repararse recupera <amount> de vida en Hit_points. USO:  (1) ENERGY
void ClapTrap::beRepaired(unsigned int amount){}


void ClapTrap::takeDamage(unsigned int amount){}

void ClapTrap::changeEnergy(){}	