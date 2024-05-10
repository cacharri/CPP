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
    // Prueba de instanciación y eliminación de objetos individuales
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

    // Prueba de polimorfismo a través del array
    for (int i = 0; i < arraySize; ++i) {
        animalArray[i]->makeSound(); // Cada animal hace su sonido específico
    }

    // Eliminación del array de Animal
    for (int i = 0; i < arraySize; ++i) {
        delete animalArray[i];
    }

    return 0;
}

