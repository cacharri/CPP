/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:08:27 by ialvarez          #+#    #+#             */
/*   Updated: 2024/04/11 19:17:14 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main() {
    Point a(0.0, 0.0);
    Point b(1.0, 0.0);
    Point c(0.5, 1.0);

    // Punto para probar (dentro del triángulo)
    Point testPointInside(0.2, 0.2);
    bool inside = bsp(a, b, c, testPointInside);
    if (inside) {
        std::cout << "El punto está dentro del triángulo." << std::endl;
    } else {
        std::cout << "El punto está fuera del triángulo." << std::endl;
    }

    // Punto para probar (fuera del triángulo)
    Point testPointOutside(1.5, 1.5);
    inside = bsp(a, b, c, testPointOutside);
    if (inside) {
        std::cout << "El punto está dentro del triángulo." << std::endl;
    } else {
        std::cout << "El punto está fuera del triángulo." << std::endl;
    }

    return 0;
}
