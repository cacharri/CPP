/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:30:37 by ialvarez          #+#    #+#             */
/*   Updated: 2024/04/25 19:13:05 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& initialName) : Name(initialName), Hit_points(10), Energy_points(10), Attack_damage(0) {
	std::cout << "Constructor for " << Name << " called" << std::endl;
}

std::string	ClapTrap::getName() const {
		return Name;
}

ClapTrap& ClapTrap::operator=(const ClapTrap other) {
	std::cout << "Assignation operator called" << std::endl;
	if (this != &other) {
		this->Name = other.Name;
	}
	return *this;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "Copy constructor called" << std::endl;
	this->Name = other.Name;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (ClapTrap::Energy_points > 0 && ClapTrap::Hit_points > 0){
		std::cout << "ClapTrap " << ClapTrap::Name << " attacks " << target << ", causing " << ClapTrap::Attack_damage << " points of damage!" << std::endl;
		ClapTrap::Energy_points--;
		ClapTrap::takeDamage(ClapTrap::Attack_damage);
	}
	else
		std::cout << "ClapTrap " << ClapTrap::Name << " can´t attacks " << target << std::endl;
}

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

int ClapTrap::getHitPoints() const {
    return Hit_points;
}

int ClapTrap::getEnergyPoints() const {
    return Energy_points;
}

int ClapTrap::getAttackDamage() const {
    return Attack_damage;
}

void ClapTrap::setHitPoints(int points) {
    this->Hit_points = points;
}

void ClapTrap::setEnergyPoints(int points) {
    this->Energy_points = points;
}

void ClapTrap::setAttackDamage(int damage) {
    this->Attack_damage = damage;
}
