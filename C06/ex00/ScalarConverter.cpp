/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:43:05 by ialvarez          #+#    #+#             */
/*   Updated: 2024/04/04 19:59:47 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& value) {
    // Convertir a char
    try {
        int intValue = atoi(value.c_str());
        if (intValue >= 0 && intValue <= 127) {
            char c = static_cast<char>(intValue);
            if (std::isprint(c)) {
                std::cout << "char: '" << c << "'" << std::endl;
            } else {
                std::cout << "char: Non displayable" << std::endl;
            }
        } else {
            std::cout << "char: impossible" << std::endl;
        }
    } catch (...) {
        std::cout << "char: impossible" << std::endl;
    }

    // Convertir a int
    try {
        int intValue = atoi(value.c_str());
        std::cout << "int: " << intValue << std::endl;
    } catch (...) {
        std::cout << "int: impossible" << std::endl;
    }

    // Convertir a float
    try {
        float floatValue = static_cast<float>(atof(value.c_str()));
        std::cout << "float: " << floatValue << "f" << std::endl;
    } catch (...) {
        std::cout << "float: impossible" << std::endl;
    }

    // Convertir a double
    try {
        double doubleValue = strtod(value.c_str(), NULL);
        std::cout << "double: " << doubleValue << std::endl;
    } catch (...) {
        std::cout << "double: impossible" << std::endl;
    }
}
