/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:08:35 by ialvarez          #+#    #+#             */
/*   Updated: 2023/08/22 21:47:35 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
	private:
		Fixed   x;
		Fixed   y;
	public:
		Point();
		~Point();
		Point(const Point& pointer);
		Point(const float i, const float j);
		Point& operator=(const Point& pointer);
		Fixed getValueX() const;
    	Fixed getValueY() const;
};

bool    bsp(Point const a, Point const b, Point const c, Point const point);

#endif
