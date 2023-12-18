/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:05:00 by ialvarez          #+#    #+#             */
/*   Updated: 2023/11/28 20:13:43 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animals.hpp"

int main() {
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    // Create and fill an array of Animal objects
    const int arraySize = 4;
    Animal* animalArray[arraySize];
    for (int i = 0; i < arraySize / 2; ++i) {
        animalArray[i] = new Dog();
        animalArray[i + arraySize / 2] = new Cat();
    }
    for (int i = 0; i < arraySize; ++i) {
        delete animalArray[i];
    }
    return 0;
}
