/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:26:07 by ialvarez          #+#    #+#             */
/*   Updated: 2023/08/24 20:29:54 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include	<iostream>
#include	<string>

class ClapTrap {
	private:
		std::string Name;
		int Hit_points = 10;
		int Energy_points = 10;
		int Attack_damage = 0;
	public:
		ClapTrap();
		ClapTrap(const std::string& initialName);
		std::string	getName() const;
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif