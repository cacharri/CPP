/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:58:00 by ialvarez          #+#    #+#             */
/*   Updated: 2024/02/14 20:48:13 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

class Zombie  {
    private:
        std::string name;
    public:
        Zombie();
        Zombie (std::string name);
        ~Zombie ();
        void announce(void);
        void setName(std::string name);
};
Zombie* zombieHorde(int N, std::string name);
