/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:32:11 by ialvarez          #+#    #+#             */
/*   Updated: 2024/04/17 19:24:28 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp" 
#include "ClapTrap.hpp"

int main() {
    ClapTrap clapTrap("ClapTrap-1");

    clapTrap.attack("Target-1");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(3);
    clapTrap.attack("Target-2");

    ScavTrap scavTrap("ScavTrap-1");

    scavTrap.attack("Target-3");
    scavTrap.takeDamage(15);
    scavTrap.beRepaired(10);
    scavTrap.guardGate();

    return 0;
}
