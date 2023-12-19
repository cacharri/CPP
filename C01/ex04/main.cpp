/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:38:05 by ialvarez          #+#    #+#             */
/*   Updated: 2023/12/19 19:22:46 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp" 

int main() {
    std::string filename, s1, s2;

    while (true) {
        std::cout << "Introduce el nombre del archivo: ";
        std::getline(std::cin, filename);
        std::ifstream inputFile(filename);
        if (!inputFile) {
            std::cout << "No se pudo abrir el archivo. Inténtalo de nuevo.\n";
            continue;
        }
        inputFile.close();
        break;
    }

    while (true) {
        std::cout << "Introduce la cadena s1: ";
        std::getline(std::cin, s1);
        if (s1.empty() || s1 == "\"\"") {
            std::cout << "La cadena s1 no puede estar vacía. Inténtalo de nuevo.\n";
            continue;
        }
        break;
    }

    while (true) {
        std::cout << "Introduce la cadena s2: ";
        std::getline(std::cin, s2);
        if (s2.empty() || s2 == "\"\"") {
            std::cout << "La cadena s2 no puede estar vacía. Inténtalo de nuevo.\n";
            continue;
        }
        break;
    }

    std::ifstream inputFile(filename);
    std::ofstream outputFile(filename + ".replace");

    std::string line;
    while (std::getline(inputFile, line)) {
        replaceAll(line, s1, s2);
        outputFile << line << '\n';
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Reemplazo completado. El nuevo archivo se ha creado: " << filename << ".replace\n";

    return 0;
}
