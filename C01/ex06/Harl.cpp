/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:22:05 by ialvarez          #+#    #+#             */
/*   Updated: 2023/12/18 16:39:52 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void    Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-picklespecial-ketchup burger. I really do!" << std::endl;
}

void    Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn´t put enough bacon in my burger! If you did, I wouldn´t be asking for more!" << std::endl;
}

void    Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level) {
	void (Harl::*fuPnt[4])(void);

	fuPnt[0] = &Harl::debug;
	fuPnt[1] = &Harl::info;
	fuPnt[2] = &Harl::warning;
	fuPnt[3] = &Harl::error;

	std::string complaints[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (level == complaints[i])
			return (this->*fuPnt[i])();
 	}
	std::cout << "Unknown level: " << level << std::endl;
}
