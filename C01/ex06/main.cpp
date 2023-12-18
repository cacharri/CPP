/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:22:36 by ialvarez          #+#    #+#             */
/*   Updated: 2023/12/18 16:51:06 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char* argv[]) {
	Harl harl;
	std::string param;
	int pos = 0;
	
	if (argc == 2) {
		param = argv[1];
		std::string option[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
		for (int i = 0; i < 4; i++)
		{
			if (param == option[i])
			{
				pos = i;
				break;
			}
		}
		switch (pos) {
		case 0:
			harl.complain("DEBUG");
		case 1:
			harl.complain("INFO");
		case 2:
			harl.complain("WARNING");
		case 3:
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
		}
	}
	return 0;
}
