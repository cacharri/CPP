/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:08:10 by ialvarez          #+#    #+#             */
/*   Updated: 2024/04/11 19:19:41 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <limits>

class Fixed {
	private:
		int value;
		static const int fractionalBits = 8;
	public:
		Fixed();

		Fixed(const int value);

		Fixed(const float value);
		
		Fixed(const double value);
		
		~Fixed();

		Fixed(const Fixed& other);

		Fixed& operator=(const Fixed& other);

		bool    operator>(const Fixed& other) const;
		bool    operator>=(const Fixed& other) const;
		bool    operator<(const Fixed& other) const;
		bool    operator<=(const Fixed& other) const;
		bool    operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;

		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		Fixed&	operator++();		// (++valor)
		Fixed	operator++(int);	// (valor++)
		Fixed&	operator--();		// (--valor)
		Fixed	operator--(int);	// (valor--)

		static const Fixed& min(const Fixed& a, const Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
		
		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;
		double toDouble() const;
		int getValue() const;
		int setValue(int newValue);
		Fixed abs() const;
};

void	modifyValue(Fixed& fixed, int newValue);

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
