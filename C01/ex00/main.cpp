/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:09:01 by ialvarez          #+#    #+#             */
/*   Updated: 2023/06/15 23:58:38 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    Zombie* zombie1 = newZombie("Zombie 1");
    zombie1->announce();

    randomChump("Zombie 2");

    delete zombie1;

    return 0;
}
