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

#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern&) {
}

Intern& Intern::operator=(const Intern& other) {
    if (this != &other) {}
    return *this;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    if (formName == "presidential pardon") {
        return new PresidentialPardonForm(target);
    } else if (formName == "shrubbery creation") {
        return new ShrubberyCreationForm(target);
    } else if (formName == "robotomy request") {
        return new RobotomyRequestForm(target);
    } else {
        std::cerr << "Error: Form " << formName << " does not exist" << std::endl;
        return nullptr;
    }
}
