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
#include "Form.hpp"

int main() {
    try {
        Bureaucrat john("John", 2);
        Form formA("FormA", 3, 5);

        std::cout << john << std::endl;
        std::cout << formA << std::endl;

        john.signForm(formA);

        Bureaucrat jane("Jane", 4);
        jane.signForm(formA);

        std::cout << formA << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat low("Low", 150);
        Form formB("FormB", 149, 150);

        std::cout << low << std::endl;
        std::cout << formB << std::endl;

        low.signForm(formB);

        std::cout << formB << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
