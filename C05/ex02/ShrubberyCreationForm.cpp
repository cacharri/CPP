/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:58:43 by ialvarez          #+#    #+#             */
/*   Updated: 2024/04/16 19:13:55 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm(target, 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    checkExecution(executor);
    std::string filename = getName() + "_shrubbery";
    std::ofstream file(filename.c_str());
    if (file.is_open()) {
        file << "      *\n"
                "     ***\n"
                "    *****\n"
                "   *******\n"
                "  *********\n"
                " ***********\n";
        file.close();
    } else {
        throw std::runtime_error("Unable to open file for writing");
    }
}

