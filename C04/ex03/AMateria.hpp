/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:17:27 by ialvarez          #+#    #+#             */
/*   Updated: 2024/02/21 19:21:50 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>

class ICharacter;

class AMateria {
	private:
		std::string material;
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria& other);
		virtual ~AMateria();
		AMateria& operator=(const AMateria& other);
		std::string const & getType() const;
		virtual AMateria* clone() const	= 0;
		virtual void use(ICharacter& target);
};

class Ice : public AMateria {
	public:
		Ice();
		Ice(const Ice& other);
		~Ice();
		AMateria* clone() const;
		void use(ICharacter& target);
};

class Cure : public AMateria {
	public:
		Cure();
		Cure(const Cure& other);
		~Cure();

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
