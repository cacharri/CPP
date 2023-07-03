/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:22:36 by ialvarez          #+#    #+#             */
/*   Updated: 2023/07/03 20:47:53 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char* argv[]) {
	Harl harl;
	std::string param;
	int option = 0;
	
	if (argc == 2) {
		param = argv[1];
		if (param == "ERROR")
			option = 1;
		else if (param == "DEBUG") 
			option = 2;
		else if (param == "INFO")
			option = 3;
		else if (param == "WARNING")
			option = 4;
	}
	switch (option) {
	case 2:
		harl.complain("DEBUG");
	case 3:
		harl.complain("INFO");
	case 4:
		harl.complain("WARNING");
	case 1:
		harl.complain("ERROR");
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
	return 0;
}
