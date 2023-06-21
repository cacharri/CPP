/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:48:58 by ialvarez          #+#    #+#             */
/*   Updated: 2023/06/20 20:00:59 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main() {
    // Creating Weapon objects
    Weapon weaponA;
    weaponA.setType("Sword");

    Weapon weaponB;
    weaponB.setType("Bow");

    // Creating HumanA and HumanB objects
    HumanA humanA("John", weaponA);
    HumanB humanB("Alice");

    // Performing attacks
    humanA.attack();
    humanB.attack();

    // Changing weapons for HumanB
    humanB.setWeapon(weaponB);
    humanB.attack();

    return 0;
}

