/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:39:06 by ialvarez          #+#    #+#             */
/*   Updated: 2023/09/19 17:20:53 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "contact.hpp"

class List {
    private:
        std::string truncateContact(std::string trncate);
    public:
        void    printContacts(Contact listContacts[8]);
        void    printContact(Contact listContacts[8], int index);
};
