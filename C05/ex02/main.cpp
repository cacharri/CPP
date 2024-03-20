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
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    Bureaucrat bureaucrat("John", 50);

    PresidentialPardonForm pardonForm("Criminal");
    ShrubberyCreationForm shrubberyForm("Garden");
    RobotomyRequestForm robotomyForm("Robot");

    try {
        shrubberyForm.beSigned(bureaucrat);
        robotomyForm.beSigned(bureaucrat);
        pardonForm.beSigned(bureaucrat);
    } catch (std::exception& e) {
        std::cerr << "Failed to sign form: " << e.what() << std::endl;
        return 1;
    }

    try {
        bureaucrat.executeForm(shrubberyForm);
        bureaucrat.executeForm(robotomyForm);
        bureaucrat.executeForm(pardonForm);
    } catch (std::exception& e) {
        std::cerr << "Failed to execute form: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
