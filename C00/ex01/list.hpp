/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:39:06 by ialvarez          #+#    #+#             */
/*   Updated: 2023/06/01 21:41:38 by ialvarez         ###   ########.fr       */
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
