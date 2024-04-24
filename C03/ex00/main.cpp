/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:25:31 by ialvarez          #+#    #+#             */
/*   Updated: 2024/04/17 19:22:23 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

int main() {
    ClapTrap player1("Player1");

    player1.attack("Enemy");
    player1.takeDamage(5);
    player1.beRepaired(3);
    player1.attack("AnotherEnemy");

    return 0;
}
