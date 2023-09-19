/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:51:58 by ialvarez          #+#    #+#             */
/*   Updated: 2023/09/19 17:20:43 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main(void)
{
	int			numbContacts;
	PhoneBook	phoneBook;
	std::string input;

	numbContacts = 0;
	while (std::cout << "Choose an option (ADD, SEARCH, EXIT): " && std::cin >> input)
	{
		if (!input.compare("ADD"))
		{
			std::cout << std::endl;
			std::cout << "- - - - Add contact - - - -" << std::endl;
			phoneBook.Addnumber(numbContacts);
			numbContacts++;
			if (numbContacts == 8)
				numbContacts = 0;
		}
		else if (!input.compare("SEARCH"))
			phoneBook.Search();
		else if (!input.compare("EXIT"))
			break;
		else
			std::cout << "Invalid command. Please try again" << std::endl;
	}
	return (0);
}
