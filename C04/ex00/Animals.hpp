/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animals.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:06:08 by ialvarez          #+#    #+#             */
/*   Updated: 2023/09/19 18:12:43 by ialvarez         ###   ########.fr       */
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
		virtual void makeSound() const;
		std::string getType() const;

	protected:
		std::string type;
};

class Dog : public Animal {
	public:
		Dog();
		virtual ~Dog();
		void makeSound() const;
};

class Cat : public Animal {
	public:
		Cat();
		virtual ~Cat();
		void makeSound() const;
};

class WrongAnimal {
	public:
		WrongAnimal();
		virtual ~WrongAnimal();
		virtual void makeSound() const;
		std::string getType() const;

	protected:
		std::string type;
};

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		virtual ~WrongCat();
};

#endif
