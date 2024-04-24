    /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:09:07 by ialvarez          #+#    #+#             */
/*   Updated: 2024/04/09 17:29:59 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed {
    private:
        int value;
        static const int fractionalBits = 8;

    public:

        Fixed();

        ~Fixed();

        Fixed(const Fixed& other);

        Fixed& operator=(const Fixed& other);

        int getRawBits() const;

        void setRawBits(int const raw);
};

#endif
