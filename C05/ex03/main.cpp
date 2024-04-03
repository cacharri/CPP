/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:27:30 by ialvarez          #+#    #+#             */
/*   Updated: 2024/04/03 20:44:57 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    // Creamos un pasante (Intern)
    Intern someRandomIntern;

    // Creamos un burócrata (Bureaucrat)
    Bureaucrat bureaucrat("John", 50);

    try {
        // El pasante crea diferentes formularios utilizando la función makeForm
        AForm* pardonForm = someRandomIntern.makeForm("presidential pardon", "Criminal");
        AForm* shrubberyForm = someRandomIntern.makeForm("shrubbery creation", "Garden");
        AForm* robotomyForm = someRandomIntern.makeForm("robotomy request", "Robot");

        // Firmamos los formularios con el burócrata
        pardonForm->beSigned(bureaucrat);
        shrubberyForm->beSigned(bureaucrat);
        robotomyForm->beSigned(bureaucrat);

        // Ejecutamos los formularios con el burócrata
        bureaucrat.executeForm(*pardonForm);
        bureaucrat.executeForm(*shrubberyForm);
        bureaucrat.executeForm(*robotomyForm);

        // Liberamos la memoria de los formularios
        delete pardonForm;
        delete shrubberyForm;
        delete robotomyForm;
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

