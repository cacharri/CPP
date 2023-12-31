/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:32:11 by ialvarez          #+#    #+#             */
/*   Updated: 2023/09/06 15:55:30 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp" 
#include "ClapTrap.hpp"

int main() {
    // Crear una instancia de ClapTrap
    ClapTrap clapTrap("ClapTrap-1");

    // Realizar una serie de acciones con ClapTrap
    clapTrap.attack("Target-1");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(3);
    clapTrap.attack("Target-2");

    // Crear una instancia de ScavTrap
    ScavTrap scavTrap("ScavTrap-1");

    // Realizar una serie de acciones con ScavTrap
    scavTrap.attack("Target-3");
    scavTrap.takeDamage(15);
    scavTrap.beRepaired(10);
    scavTrap.guardGate();

    return 0;
}
