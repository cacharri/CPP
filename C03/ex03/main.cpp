/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:32:11 by ialvarez          #+#    #+#             */
/*   Updated: 2023/09/06 17:54:33 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {

    // Crea instancias de cada clase y sus heredadas
    ClapTrap claptrap("Vanido");
    ScavTrap scavtrap("Lost mind");
    FragTrap fragtrap("Croac");

    // Probando las funciones de ClapTrap
    claptrap.attack("Target 1");
    claptrap.takeDamage(10);
    claptrap.beRepaired(5);

    // Probando las funciones de ScavTrap
    scavtrap.attack("Target 2");
    scavtrap.takeDamage(15);
    scavtrap.beRepaired(7);
    scavtrap.guardGate(); // Función especial de ScavTrap

    // Probando las funciones de FragTrap
    fragtrap.attack("Target 3");
    fragtrap.takeDamage(20);
    fragtrap.beRepaired(10);
    fragtrap.highFivesGuys(); // Función especial de FragTrap

    return 0;
}
