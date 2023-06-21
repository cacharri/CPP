/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:49:58 by ialvarez          #+#    #+#             */
/*   Updated: 2023/06/20 20:00:02 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& newName)
    : name(newName), weapon(nullptr) {}

HumanB::~HumanB() {
    delete weapon;
}

void HumanB::setWeapon(const Weapon& newWeapon) {
    delete weapon;
    weapon = new Weapon(newWeapon); // Crea una copia del objeto Weapon en el heap
}

void HumanB::attack() const {
    if (weapon != nullptr) {
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    } else {
        std::cout << name << " is unarmed and cannot attack." << std::endl;
    }
}


