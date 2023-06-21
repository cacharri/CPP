/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:47:39 by ialvarez          #+#    #+#             */
/*   Updated: 2023/06/20 19:25:29 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    Zombie* horde = new Zombie[N]; // Reservar memoria para N objetos Zombie

    for (int i = 0; i < N; i++) {
        horde[i].setName(name + ' ' + std::to_string(i+1)); // Asignar un nombre único a cada zombi
    }

    return horde; // Retornar un puntero al primer zombi
}
