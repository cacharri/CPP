/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:17:27 by ialvarez          #+#    #+#             */
/*   Updated: 2024/02/13 19:19:15 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class AMateria {
	private:
		std::string material;
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria& other);
		~AMateria();
		AMateria& operator=(const AMateria& other);
		std::string const & getType() const;
		virtual AMateria* clone() const	= 0;
		virtual void use(ICharacter& target);
};

class Ice : public AMateria {
	public:
    Ice();
		virtual ~Ice();
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

class Cure : public AMateria {
	public:
		Cure();
		virtual ~Cure();
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};


#endif
