/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:27:30 by ialvarez          #+#    #+#             */
/*   Updated: 2024/03/20 18:03:04 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat john("John", 1);
        Bureaucrat jane("Jane", 50);

        ShrubberyCreationForm form1("home");
        RobotomyRequestForm form2("office");
        PresidentialPardonForm form3("Alice");

        john.signForm(form1);
        john.signForm(form2);
        john.signForm(form3);

        john.executeForm(form1);
        john.executeForm(form2);
        john.executeForm(form3);

        jane.executeForm(form1);
        jane.executeForm(form2);
        // Jane no puede ejecutar el formulario de perdón presidencial porque su grado es insuficiente
        try {
            jane.executeForm(form3);
        } catch (const std::exception& e) {
            std::cerr << "Jane no pudo ejecutar el formulario: " << e.what() << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

