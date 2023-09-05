/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:30:27 by ialvarez          #+#    #+#             */
/*   Updated: 2023/09/05 22:11:58 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include	<iostream>
#include	<string>

class ClapTrap {
	private:
		std::string Name;
		unsigned int Hit_points;
		unsigned int Energy_points;
		unsigned int Attack_damage;
	public:
		ClapTrap();
		ClapTrap(const std::string& initialName);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap other);
		std::string	getName() const;
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		// Getters
		int getHitPoints() const;
    	int getEnergyPoints() const;
    	int getAttackDamage() const;
		// Setters
    	void setHitPoints(int points);
    	void setEnergyPoints(int points);
 		void setAttackDamage(int damage);
};

#endif
