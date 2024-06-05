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
    try {
        Intern someRandomIntern;

        Bureaucrat bureaucrat("John", 2);

        AForm* pardonForm = someRandomIntern.makeForm("presidential pardon", "Criminal");
        AForm* shrubberyForm = someRandomIntern.makeForm("shrubbery creation", "Garden");
        AForm* robotomyForm = someRandomIntern.makeForm("robotomy request", "Robot");

        pardonForm->beSigned(bureaucrat);
        shrubberyForm->beSigned(bureaucrat);
        robotomyForm->beSigned(bureaucrat);

        bureaucrat.executeForm(*pardonForm);
        bureaucrat.executeForm(*shrubberyForm);
        bureaucrat.executeForm(*robotomyForm);

        AForm* invalidForm = someRandomIntern.makeForm("invalid form", "Nobody");
        if (invalidForm == NULL) {
            std::cout << "Invalid form creation handled correctly." << std::endl;
        } else {
            std::cerr << "Error: Invalid form creation should return nullptr." << std::endl;
            delete invalidForm;
        }

        delete pardonForm;
        delete shrubberyForm;
        delete robotomyForm;
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

