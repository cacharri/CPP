/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:50:03 by ialvarez          #+#    #+#             */
/*   Updated: 2024/04/16 19:41:22 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <random>

class Base {
    public:
        virtual ~Base() {}
        Base * generate(void);
};

class A : Base {};
class B : Base {};
class C : Base {};

void identify(Base* p);
void identify(Base& p); 



#endif
