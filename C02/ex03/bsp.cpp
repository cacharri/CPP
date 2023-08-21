/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:08:32 by ialvarez          #+#    #+#             */
/*   Updated: 2023/08/21 22:39:04 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Función para calcular el área de un triángulo dado por tres puntos.
double areaOfTriangle(const Point& a, const Point& b, const Point& c) {
    return 0.5 * a.getValueX() * (b.getValueY() - c.getValueY()) +
                     b.getValueX() * (c.getValueY() - a.getValueY()) +
                     c.getValueX() * (a.getValueY() - b.getValueY()).abs();
}


bool bsp(Point const a, Point const b, Point const c, Point const point) {

    Fixed xCoordA = a.getValueX().getValue();
    Fixed yCoordA = a.getValueY().getValue();
    
    Fixed xCoordB = b.getValueX().getValue();
    Fixed yCoordB = b.getValueY().getValue();
    
    Fixed xCoordC = c.getValueX().getValue();
    Fixed yCoordC = c.getValueY().getValue();
    
    Fixed xCoordPoint = point.getValueX().getValue();
    Fixed yCoordPoint = point.getValueY().getValue();

    
}
