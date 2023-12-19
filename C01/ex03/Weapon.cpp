/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:50:18 by ialvarez          #+#    #+#             */
/*   Updated: 2023/12/19 19:19:02 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

#include <iostream>

Weapon::Weapon(const std::string& name) : type(name) {}

Weapon::~Weapon() {}
const std::string& Weapon::getType() const {
    return type;
}

void Weapon::setType(const std::string& newType) {
    this->type = newType;
}
