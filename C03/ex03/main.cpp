/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:32:11 by ialvarez          #+#    #+#             */
/*   Updated: 2024/04/25 20:28:47 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
    // Crear un DiamondTrap
    DiamondTrap diamondTrap("Diamond");

    // Llamar a las funciones heredadas
    diamondTrap.takeDamage(20);
    diamondTrap.beRepaired(10);
    diamondTrap.ScavTrap::attack("Target");

    // Llamar a la función especial de DiamondTrap
    diamondTrap.whoAmI();

    return 0;
}


