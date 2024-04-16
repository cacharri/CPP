/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:58:58 by ialvarez          #+#    #+#             */
/*   Updated: 2024/04/16 19:18:40 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {}

void RobotomyRequestForm::execute(const Bureaucrat&) const {
    bool success = (rand() % 2) == 0;
    std::cout << "Making some drilling noises..." << std::endl;
    if (success) {
        std::cout << getName() << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy on " << getName() << " failed." << std::endl;
    }
}
