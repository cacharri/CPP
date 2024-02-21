/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:58:28 by ialvarez          #+#    #+#             */
/*   Updated: 2024/02/21 19:04:06 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

Character::Character() {}

Character::Character(std::string const & name) : name(name) {
    for (int i = 0; i < 4; ++i) {
        slot[i] = nullptr;
    }
}

Character::~Character() {
    for (int i = 0; i < 4; ++i) {
        delete slot[i];
    }
}

std::string const & Character::getName() const {
    return name;
}

Character::Character(const Character& other) : name(other.name) {
    for (int i = 0; i < 4; ++i) {
        if (other.slot[i] != nullptr) {
            slot[i] = other.slot[i]->clone();
        } else {
            slot[i] = nullptr;
        }
    }
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        name = other.name;
        for (int i = 0; i < 4; ++i) {
            delete slot[i];
            if (other.slot[i] != nullptr) {
                slot[i] = other.slot[i]->clone();
            } else {
                slot[i] = nullptr;
            }
        }
    }
    return *this;
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; ++i) {
        if (slot[i] == nullptr) {
            slot[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && slot[idx] != nullptr) {
        delete slot[idx];
        slot[idx] = nullptr;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && slot[idx]) {
        slot[idx]->use(target);
    }
}

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        learnedMaterias[i] = nullptr;
    }
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        delete learnedMaterias[i];
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; ++i) {
        if (!learnedMaterias[i]) {
            learnedMaterias[i] = m->clone();
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; ++i) {
        if (learnedMaterias[i] && learnedMaterias[i]->getType() == type) {
            return learnedMaterias[i]->clone();
        }
    }
    return nullptr;
}
