/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animals.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:06:08 by ialvarez          #+#    #+#             */
/*   Updated: 2023/11/20 19:03:43 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMALS_HPP
#define ANIMALS_HPP

#include <string>
#include <iostream>

class Animal {
	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual void makeSound() const;
		std::string getType() const;

	protected:
		std::string type;
};

class Dog : public Animal {
	public:
		Dog();
		~Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		void makeSound() const;
};

class Cat : public Animal {
	public:
		Cat();
		Cat(const Cat& other);
		~Cat();
		Cat& operator=(const Cat& other);
		void makeSound() const;
};

class WrongAnimal {
	public:
		WrongAnimal();
		virtual ~WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);
		virtual void makeSound() const;
		std::string getType() const;

	protected:
		std::string type;
};

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat& other);
		WrongCat& operator=(const WrongCat& other);
		void makeSoundCat() const;
};

#endif
