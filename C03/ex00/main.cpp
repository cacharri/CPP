/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:25:31 by ialvarez          #+#    #+#             */
/*   Updated: 2023/08/29 19:32:38 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.hpp" // Asumiendo que tienes un archivo de encabezado llamado ClapTrap.hpp que contiene la definición de la clase ClapTrap

int main() {
    // Crear una instancia de ClapTrap con el nombre "Player1"
    ClapTrap player1("Player1");

    // Realizar algunas acciones para probar los métodos
    player1.attack("Enemy");
    player1.takeDamage(5);
    player1.beRepaired(3);
    player1.attack("AnotherEnemy");

    return 0;
}
