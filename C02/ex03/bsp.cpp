/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:08:32 by ialvarez          #+#    #+#             */
/*   Updated: 2023/08/22 22:35:13 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed d1 = (b.getValueX() - a.getValueX()) * (point.getValueY() - a.getValueY()) - (b.getValueY() - a.getValueY()) * (point.getValueX() - a.getValueX());
    Fixed d2 = (c.getValueX() - b.getValueX()) * (point.getValueY() - b.getValueY()) - (c.getValueY() - b.getValueY()) * (point.getValueX() - b.getValueX());
    Fixed d3 = (a.getValueX() - c.getValueX()) * (point.getValueY() - c.getValueY()) - (a.getValueY() - c.getValueY()) * (point.getValueX() - c.getValueX());

    bool isOnVertex = (d1 == 0 && point.getValueX() == a.getValueX() && point.getValueY() == a.getValueY()) ||
                  (d2 == 0 && point.getValueX() == b.getValueX() && point.getValueY() == b.getValueY()) ||
                  (d3 == 0 && point.getValueX() == c.getValueX() && point.getValueY() == c.getValueY());
    bool isOnSideAB = d1 == 0 && point.getValueX() >= Fixed::min(a.getValueX(), b.getValueX()) && point.getValueX() <= Fixed::max(a.getValueX(), b.getValueX());
    bool isOnSideBC = d2 == 0 && point.getValueX() >= Fixed::min(b.getValueX(), c.getValueX()) && point.getValueX() <= Fixed::max(b.getValueX(), c.getValueX());
    bool isOnSideCA = d3 == 0 && point.getValueX() >= Fixed::min(c.getValueX(), a.getValueX()) && point.getValueX() <= Fixed::max(c.getValueX(), a.getValueX());

    return isOnVertex || isOnSideAB || isOnSideBC || isOnSideCA ||
           (d1 >= 0 && d2 >= 0 && d3 >= 0) || (d1 <= 0 && d2 <= 0 && d3 <= 0);
}
