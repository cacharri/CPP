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
        slot[i] = NULL;
    }
}

Character::~Character() {
}


std::string const & Character::getName() const {
    return name;
}

Character::Character(const Character& other) : name(other.name) {
    for (int i = 0; i < 4; ++i) {
        if (other.slot[i] != NULL) {
            slot[i] = other.slot[i]->clone();
        } else {
            slot[i] = NULL;
        }
    }
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        name = other.name;
        for (int i = 0; i < 4; ++i) {
            delete slot[i];
            if (other.slot[i] != NULL) {
                slot[i] = other.slot[i]->clone();
            } else {
                slot[i] = NULL;
            }
        }
    }
    return *this;
}

void Character::equip(AMateria* m) {
    int emptySlot = -1;
    for (int i = 0; i < 4; ++i) {
        if (slot[i] == NULL) {
            emptySlot = i;
            break;
        }
    }
    if (emptySlot != -1) {
        slot[emptySlot] = m;
    } else {
        std::cout << "Cannot equip more than 4 materias." << std::endl;
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && slot[idx] != NULL) {
        slot[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && slot[idx]) {
        slot[idx]->use(target);
    }
}

void Character::printEquippedMaterias() const {
    for (int i = 0; i < 4; ++i) {
        if (slot[i] != NULL) {
            std::cout << "Slot " << i + 1 << ": " << slot[i]->getType() << std::endl;
        } else {
            std::cout << "Slot " << i + 1 << ": Empty" << std::endl;
        }
    }
}

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        learnedMaterias[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    for (int i = 0; i < 4; ++i) {
        if (other.learnedMaterias[i] != NULL) {
            learnedMaterias[i] = other.learnedMaterias[i]->clone();
        } else {
            learnedMaterias[i] = NULL;
        }
    }
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        if (learnedMaterias[i] != NULL) {
            delete learnedMaterias[i];
            learnedMaterias[i] = NULL;
        }
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            if (learnedMaterias[i] != NULL) {
                delete learnedMaterias[i];
            }
            if (other.learnedMaterias[i] != NULL) {
                learnedMaterias[i] = other.learnedMaterias[i]->clone();
            } else {
                learnedMaterias[i] = NULL;
            }
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; ++i) {
        if (!learnedMaterias[i]) {
            learnedMaterias[i] = m;
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
    return NULL;
}
