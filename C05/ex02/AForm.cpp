/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <ialvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:23:55 by ialvarez          #+#    #+#             */
/*   Updated: 2024/03/20 17:40:17 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form not signed";
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) :
    _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {}

AForm::AForm(const AForm& other) :
    _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const {
    return _name;
}

bool AForm::getIsSigned() const {
    return _isSigned;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bureau) {
    if (bureau.getGrade() <= _gradeToSign) {
        _isSigned = true;
    } else {
        throw GradeTooLowException();
    }
}

void AForm::checkExecution(const Bureaucrat& executor) const {
    if (!_isSigned) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > _gradeToExecute) {
        throw GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No") << ", Grade to sign: " << form.getGradeToSign() << ", Grade to execute: " << form.getGradeToExecute();
    return os;
}
