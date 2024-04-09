/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:51:50 by ialvarez          #+#    #+#             */
/*   Updated: 2024/04/04 19:55:02 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main() {
    std::cout << "Pruebas de conversión con diferentes tipos de literales:" << std::endl;

    ScalarConverter::convert("0");
    ScalarConverter::convert("-42");
    ScalarConverter::convert("42.0");
    ScalarConverter::convert("-42.0");
    ScalarConverter::convert("0.0");
    ScalarConverter::convert("-0.0");
    ScalarConverter::convert("4.2f");
    ScalarConverter::convert("-4.2f");
    ScalarConverter::convert("inff");
    ScalarConverter::convert("-inff");
    ScalarConverter::convert("nanf");
    ScalarConverter::convert("inf");
    ScalarConverter::convert("-inf");
    ScalarConverter::convert("nan");

    return 0;
}

