/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:27:30 by ialvarez          #+#    #+#             */
/*   Updated: 2024/02/28 18:05:27 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bureaucrat("John Doe", 100);
        std::cout << bureaucrat << std::endl;

        bureaucrat.incrementGrade();
        std::cout << bureaucrat << std::endl;

        bureaucrat.decrementGrade();
        std::cout << bureaucrat << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat bureaucrat_high("John Doe", 0);
        std::cout << "Bureaucrat created successfully!" << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Error creating bureaucrat: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Error creating bureaucrat: " << e.what() << std::endl;
    }

    try {
        Bureaucrat bureaucrat_low("Jane Smith", 200);
        std::cout << "Bureaucrat created successfully!" << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Error creating bureaucrat: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Error creating bureaucrat: " << e.what() << std::endl;
    }
    return 0;
}
