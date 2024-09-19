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

    if (value == "nan" || value == "nanf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }
    if (value == "+inf" || value == "inf" || value == "+inff" || value == "inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
        return;
    }
    if (value == "-inf" || value == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return;
    }

    int intValue = 0;
    try {
        intValue = atoi(value.c_str());
        std::cout << "int: " << intValue << std::endl;
    } catch (...) {
        std::cout << "int: impossible" << std::endl;
    }

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

    try {
        float floatValue = static_cast<float>(atof(value.c_str()));
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << floatValue << "f" << std::endl;
    } catch (...) {
        std::cout << "float: impossible" << std::endl;
    }

    try {
        double doubleValue = strtod(value.c_str(), NULL);
        std::cout << "double: " << doubleValue << std::endl;
    } catch (...) {
        std::cout << "double: impossible" << std::endl;
    }
}

