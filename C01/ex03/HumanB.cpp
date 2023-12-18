/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:49:58 by ialvarez          #+#    #+#             */
/*   Updated: 2023/12/17 21:14:32 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& newName)
    : name(newName), weapon(nullptr) {}

HumanB::~HumanB() {
}

void HumanB::setWeapon(Weapon &newWeapon) {
    weapon = &newWeapon;
}

void HumanB::attack() const {
    if (weapon != nullptr) {
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    } else {
        std::cout << name << " is unarmed and cannot attack." << std::endl;
    }
}


