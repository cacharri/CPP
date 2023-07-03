/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:22:05 by ialvarez          #+#    #+#             */
/*   Updated: 2023/07/03 18:38:05 by ialvarez         ###   ########.fr       */
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
	void (Harl::*funcPtr)() = nullptr;   //estoo se puedde usar de esta manera?

	if (level == "DEBUG") {
		funcPtr = &Harl::debug;
	}
	else if (level == "INFO") {
		funcPtr = &Harl::info;
	}
	else if (level == "WARNING") {
		funcPtr = &Harl::warning;
	}
	else if (level == "ERROR") {
		funcPtr = &Harl::error;
	}
	if (funcPtr != nullptr) {
		(this->*funcPtr)();
	}
	else {
		std::cout << "Unknown level: " << level << std::endl;
	}
}
