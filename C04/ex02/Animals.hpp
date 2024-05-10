/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animals.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:33:44 by ialvarez          #+#    #+#             */
/*   Updated: 2023/11/28 20:13:01 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMALS_HPP
#define ANIMALS_HPP

#include <string>
#include <iostream>

class Brain	{
	private:
		std::string ideas[100];
	public:
		Brain();
		~Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
};

class AAnimal {
	public:
		AAnimal();
		virtual ~AAnimal();
		AAnimal(const AAnimal& other);
		AAnimal& operator=(const AAnimal& other);
		virtual void makeSound() const = 0;
		std::string getType() const;

	protected:
		std::string type;
};

class Dog : public AAnimal {
	private:
		Brain* brain;
	public:
		Dog();
		~Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		void makeSound() const;
};

class Cat : public AAnimal {
	private:
		Brain* brain;
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
