/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:48:35 by ialvarez          #+#    #+#             */
/*   Updated: 2023/09/19 19:42:24 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void PhoneBook::Addnumber(int numContacts)
{
    listContacts[numContacts].Add();
    std::cout << "- - - - Contact added successfully - - - -" << std::endl;
}

void PhoneBook::Search()
{
	int			index;
	List		listContact;
	std::string	in;
	
	listContact.printContacts(listContacts);
	std::cout << std::endl;
	std::cout << "Select a contact from the list: ";
	std::getline(std::cin >> std::ws, in);
	std::stringstream(in) >> index;
	listContact.printContact(listContacts, index);
}
