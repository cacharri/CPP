/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:27:54 by ialvarez          #+#    #+#             */
/*   Updated: 2024/03/05 18:38:56 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <string>

class Bureaucrat {
private:
    const std::string _name;
    int _grade;

public:
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw() ;
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw() ;
    };
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signForm();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
