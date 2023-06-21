/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:11:53 by ialvarez          #+#    #+#             */
/*   Updated: 2023/06/01 21:39:53 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>

class Contact {
	
    private:
        std::string firstname;
        std::string lastname;
        std::string nickname;
        std::string phonenumber;
        std::string darkestsecret;
    
    public:
		void    Add();
		void	Search(int i);
        
		
        std::string getName()
		{
			return firstname;
		}
		std::string getLastname()
		{
			return lastname;
		}
		std::string getNickname()
		{
			return nickname;
		}
};
