/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:41:07 by ialvarez          #+#    #+#             */
/*   Updated: 2024/04/03 20:46:41 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern&) {
}

Intern& Intern::operator=(const Intern& other) {
    if (this != &other) {}
    return *this;
}
*/
/*AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    if (formName == "presidential pardon") {
        return new PresidentialPardonForm(target);
    } else if (formName == "shrubbery creation") {
        return new ShrubberyCreationForm(target);
    } else if (formName == "robotomy request") {
        return new RobotomyRequestForm(target);
    } else {
        std::cerr << "Error: Form " << formName << " does not exist" << std::endl;
        return NULL;
    }
}*/
/*AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    // Definición de la estructura FormType
    struct FormType {
        const char* name;
        AForm* (*create)(const std::string& target);
    };

    // Inicialización del arreglo forms
    const FormType forms[] = {
        {"presidential pardon", PresidentialPardonForm},
        {"shrubbery creation", ShrubberyCreationForm},
        {"robotomy request", RobotomyRequestForm},
    };

    const size_t formsCount = sizeof(forms) / sizeof(forms[0]);

    for (size_t i = 0; i < formsCount; ++i) {
        if (formName == forms[i].name) {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].create(target);
        }
    }

    std::cerr << "Error: Form " << formName << " does not exist" << std::endl;
    return NULL;
}*/
#include "Intern.hpp"
#include <iostream>
#include <string>

// Declaraciones de las funciones creadoras
AForm* createPresidentialPardonForm(const std::string& target);
AForm* createShrubberyCreationForm(const std::string& target);
AForm* createRobotomyRequestForm(const std::string& target);

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& other) {
    *this = other;
}

Intern& Intern::operator=(const Intern& other) {
    if (this != &other) {
        // Asignar atributos si los tuviera
    }
    return *this;
}

// Definición de las funciones creadoras
AForm* createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* createShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* createRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    // Definición de la estructura FormType
    struct FormType {
        const char* name;
        AForm* (*create)(const std::string& target);
    };

    // Inicialización del arreglo forms
    const FormType forms[] = {
        {"presidential pardon", createPresidentialPardonForm},
        {"shrubbery creation", createShrubberyCreationForm},
        {"robotomy request", createRobotomyRequestForm},
    };

    const size_t formsCount = sizeof(forms) / sizeof(forms[0]);

    for (size_t i = 0; i < formsCount; ++i) {
        if (formName == forms[i].name) {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].create(target);
        }
    }

    std::cerr << "Error: Form " << formName << " does not exist" << std::endl;
    return NULL;
}

