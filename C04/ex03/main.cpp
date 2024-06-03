/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:16:42 by ialvarez          #+#    #+#             */
/*   Updated: 2024/02/21 19:28:27 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "AMateria.hpp"

int main() {
    // Crear una fuente de Materias y aprender dos tipos de Materia
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    // Crear un personaje "me"
    ICharacter* me = new Character("me");
    AMateria* ice = src->createMateria("ice");
    me->equip(ice);
    AMateria* cure = src->createMateria("cure");
    me->equip(cure);

    // Crear un personaje "bob"
    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    // Crear un personaje
    Character* player = new Character("Player");

    AMateria* ice1 = new Ice();
    AMateria* ice2 = new Ice();
    AMateria* ice3 = new Ice();
    AMateria* ice4 = new Ice();
    AMateria* ice5 = new Ice();
    AMateria* cure1 = new Cure();
    AMateria* cure2 = new Cure();
    AMateria* cure3 = new Cure();
    AMateria* cure4 = new Cure();
    AMateria* cure5 = new Cure();

    player->equip(ice1);
    player->equip(ice2);
    player->equip(cure1);
    player->equip(cure2);
    player->equip(ice3);
    player->equip(ice4);
    player->equip(ice5);
    player->equip(cure3);
    player->equip(cure4);
    player->equip(cure5);

    std::cout << "Armas equipadas:\n" << std::endl;
    player->printEquippedMaterias();

    delete player;
    delete ice5;
    delete ice4;
    delete ice3;
    delete ice2;
    delete ice1;
    delete cure1;
    delete cure2;
    delete cure3;
    delete cure4;
    delete cure5;
    delete ice;
    delete cure;

    return 0;
}

