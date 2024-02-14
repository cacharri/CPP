/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:47:11 by ialvarez          #+#    #+#             */
/*   Updated: 2024/02/14 20:54:07 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	int N = 0;

	std::cout << "Ingresa la cantidad de zombies para la horda: " << std::endl;
    while (true) {
        std::cin >> N;
        if (std::cin.fail() || N <= 0) {
            if (std::cin.eof()) {
                std::cout << "Se alcanzó el final del archivo (EOF). Saliendo del programa." << std::endl;
                return 1;
            }
            std::cout << "Ingresa un número positivo" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
	while(true) {
		if (std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'))
			break ;
		else {
			std::cin.clear();
			while (std::cin.get() != '\n') {
					continue;
			}
			std::cout << "Por favor, ingresa números: " << std::endl;
			std::cin >> N;
		}
	}
	std::string zombieName;
	std::cout << "Ingresa el nombre para los zombies: " << std::endl;
	std::cin >> zombieName;
	Zombie* horde = zombieHorde(N, zombieName);
	for (int i = 0; i < N; i++) {
		horde[i].announce();
	}
	delete[] horde;
	return(0);
}
