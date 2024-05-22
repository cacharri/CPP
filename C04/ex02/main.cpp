/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:13:29 by ialvarez          #+#    #+#             */
/*   Updated: 2023/11/28 20:14:10 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animals.hpp"

int main() {
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    delete j;
    delete i;

    const int arraySize = 4;
    AAnimal* animalArray[arraySize];
    for (int i = 0; i < arraySize / 2; ++i) {
        animalArray[i] = new Dog();
        animalArray[i + arraySize / 2] = new Cat();
    }

    for (int i = 0; i < arraySize; ++i) {
        animalArray[i]->makeSound();
    }

    for (int i = 0; i < arraySize; ++i) {
        delete animalArray[i];
    }

    return 0;
}

