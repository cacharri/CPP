/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:56:28 by ialvarez          #+#    #+#             */
/*   Updated: 2023/06/01 21:40:27 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "list.hpp"

class PhoneBook {    
        
    private:
        Contact listContacts[8];
    public:
        void    Addnumber(int numbContacts);
        void    Search();
};
