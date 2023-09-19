/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:11:49 by ialvarez          #+#    #+#             */
/*   Updated: 2023/09/19 17:20:47 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

void    Contact::Add()
{
    std::cout << "Name: ";
    std::getline(std::cin >> std::ws, firstname);
    std::cout << "Last Name: ";
    std::getline(std::cin, lastname);
    std::cout << "Nickname: ";
    std::getline(std::cin, nickname);
	bool valid = false;
        do {
            std::cout << "Phone: ";
            std::getline(std::cin, phonenumber);
            valid = true;
            for (size_t i = 0; i < phonenumber.length(); ++i) {
                if (!isdigit(phonenumber[i])) {
                    valid = false;
                    break;
                }
            }
            if (!valid) {
                std::cout << "El número de teléfono debe contener solo números. Inténtalo de nuevo." << std::endl;
            }
        } while (!valid);
    std::cout << "Darkest secret: ";
    std::getline(std::cin, darkestsecret);
}

void	Contact::Search(int i)
{
	std::cout << std::endl << std::setw(10) << "Contact: " << i << std::endl;
	std::cout << std::setw(10) << "Name: " << firstname << std::endl;
	std::cout << std::setw(10) << "Lastname: " << lastname << std::endl;
	std::cout << std::setw(10) << "Nickname: " << nickname << std::endl;
	std::cout << std::setw(10) << "Phone: " << phonenumber << std::endl;
	std::cout << std::setw(10) << "Secret: " << darkestsecret << std::endl;
}
