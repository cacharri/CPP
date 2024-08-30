/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:24:04 by ialvarez          #+#    #+#             */
/*   Updated: 2024/03/20 16:35:05 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;

    public:
        class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw();
        };
        class FormNotSignedException : public std::exception {
        public:
            const char* what() const throw();
        };
        AForm();
        AForm(const std::string& name, int _gradeToSign, int _gradeToExecute);
        virtual ~AForm();
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(const Bureaucrat& bureau);
        virtual void execute(const Bureaucrat& executor) const = 0;
        void checkExecution(const Bureaucrat& executor) const;
    };

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
