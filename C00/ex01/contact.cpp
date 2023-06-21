/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:11:49 by ialvarez          #+#    #+#             */
/*   Updated: 2023/06/05 18:35:08 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

void    Contact::Add()
{
    std::cout << "Name: ";
	std::getline(std::cin, firstname);
	std::cout << "Last Name: ";
	std::getline(std::cin, lastname);
	std::cout << "Nickname: ";   
	std::getline(std::cin, nickname);
	std::cout << "Phone: ";
	std::getline(std::cin, phonenumber);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, darkestsecret);
}
/*
void Contact::addContact() {
        if (numContacts == 8) {
            // Replace the oldest contact with the new one
            for (int i = 0; i < 8 - 1; i++) {
                contacts[i] = contacts[i + 1];
            }
            list[8 - 1] = contact;
        } else {
            contacts[numContacts] = contact;
            numContacts++;
        }
    }
*/
void	Contact::Search(int i)
{
	std::cout << std::endl << std::setw(10) << "Contact: " << i << std::endl;
	std::cout << std::setw(10) << "Name: " << firstname << std::endl;
	std::cout << std::setw(10) << "Lastname: " << lastname << std::endl;
	std::cout << std::setw(10) << "Nickname: " << nickname << std::endl;
	std::cout << std::setw(10) << "Phone: " << phonenumber << std::endl;
	std::cout << std::setw(10) << "Secret: " << darkestsecret << std::endl;
}
