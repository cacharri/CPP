/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:32:11 by ialvarez          #+#    #+#             */
/*   Updated: 2023/09/05 22:39:07 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp" 
#include "ClapTrap.hpp"
/*
int main() {
    // Crear una instancia de ClapTrap con el nombre "Player1"
    ClapTrap player1("Player1");

    // Realizar algunas acciones para probar los métodos
    player1.attack("Enemy");
    player1.takeDamage(5);
    player1.beRepaired(3);
    player1.attack("AnotherEnemy");

    return 0;
}*/
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
