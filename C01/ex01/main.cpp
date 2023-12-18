/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:47:11 by ialvarez          #+#    #+#             */
/*   Updated: 2023/12/17 19:16:19 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	int N = 0;

	std::cout << "Ingresa la cantidad de zombies para la horda: " << std::endl;
	std::cin >> N;
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
