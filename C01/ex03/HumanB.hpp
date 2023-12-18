/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:50:12 by ialvarez          #+#    #+#             */
/*   Updated: 2023/12/17 21:12:56 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB {
	private:
		std::string name;
		Weapon* weapon;

	public:
		HumanB(const std::string& newName);
		~HumanB();
		void setWeapon(Weapon &newWeapon);
		void attack() const;
};

#endif
