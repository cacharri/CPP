/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:27:40 by ialvarez          #+#    #+#             */
/*   Updated: 2023/06/20 19:36:42 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    // Direcciones de memoria
    std::cout << "Dirección de memoria de la variable str: " << &str << std::endl;
    std::cout << "Dirección de memoria contenida en stringPTR: " << stringPTR << std::endl;
    std::cout << "Dirección de memoria contenida en stringREF: " << &stringREF << std::endl;

    // Valores de la variable, el puntero y la referencia
    std::cout << "Valor de la variable str: " << str << std::endl;
    std::cout << "Valor apuntado por stringPTR: " << *stringPTR << std::endl;
    std::cout << "Valor apuntado por stringREF: " << stringREF << std::endl;

    return 0;
}
