/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:58:32 by ialvarez          #+#    #+#             */
/*   Updated: 2024/02/21 19:27:47 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "AMateria.hpp"

class AMateria;

class ICharacter {
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

class Character : public ICharacter {
	private:
		std::string name;
		AMateria* slot[4];

	public:
		Character();
		Character(std::string const & name);
		~Character();
		Character(Character const &other); 
		Character &operator=(Character const &other);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		void printEquippedMaterias() const;
};

class IMateriaSource {
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria* m) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource {
	private:
    	AMateria* learnedMaterias[4];

	public:
    	MateriaSource();
    	MateriaSource(const MateriaSource& other);
    	virtual ~MateriaSource();
    	MateriaSource& operator=(const MateriaSource& other);
    	virtual void learnMateria(AMateria* m);
    	virtual AMateria* createMateria(std::string const & type);
};

#endif
