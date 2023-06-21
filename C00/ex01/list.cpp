/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:39:24 by ialvarez          #+#    #+#             */
/*   Updated: 2023/06/01 21:41:54 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"

std::string List::truncateContact(std::string trncate) {

    if (trncate.length() > 10) 
    {
        return trncate.substr(0, 9) + ".";
    }
    return trncate;
}

/*void printContacts() const {
        std::cout << "Contact List:" << std::endl;
        std::cout << std::setw(10) << "Index |" << std::setw(10) << "First Name |" << std::setw(10)
                  << "Last Name |" << std::setw(10) << "Nickname" << std::endl;

        for (int i = 0; i < numContacts; i++) {
            std::cout << std::setw(10) << i << " |";
            std::cout << std::setw(10) << truncateString(contacts[i].getFirstName(), 10) << " |";
            std::cout << std::setw(10) << truncateString(contacts[i].getLastName(), 10) << " |";
            std::cout << std::setw(10) << truncateString(contacts[i].getNickname(), 10) << std::endl;
        }
    };
*/
void   List::printContacts(Contact listContacts[8])
{
    std::cout << std::endl;
    std::cout << std::setw(11) << "Index|";
	std::cout << std::setw(11) << "Name|";
	std::cout << std::setw(11) << "Lastname|";
	std::cout << std::setw(11) << "Nickname|";
	std::cout << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << std::setw(10) << i + 1 << "|";
		std::cout << std::setw(10) << truncateContact(listContacts[i].getName()) << "|";
		std::cout << std::setw(10) << truncateContact(listContacts[i].getLastname()) << "|";
		std::cout << std::setw(10) << truncateContact(listContacts[i].getNickname()) << "|";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void    List::printContact(Contact listContacts[8], int index)
{
	if (index > 0 && index < 9)
	{
		if (listContacts[index -1].getName().empty())
			std::cout << "" << std::endl;
		else
			listContacts[index - 1].Search(index);
	}
	else
		std::cout << "Could not find contact" << std::endl;
}
