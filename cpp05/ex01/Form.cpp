/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 13:10:26 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/03 16:59:41 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Contract"), _signed(false), _sign_grade(1), _exec_grade(1)
{
}

Form::Form(Form const &src)
: _name(src._name), _signed(src._signed), _sign_grade(src._sign_grade), _exec_grade(src._exec_grade)
{
    *this = src;
}

Form::Form(const std::string &name, const int &sign_grade, const int &exec_grade)
: _name(name), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw (Form::GradeTooHighException());
	if (sign_grade > 150 || exec_grade > 150)
		throw (Form::GradeTooLowException());
}

Form::~Form()
{
}

Form& Form::operator=(const Form &src)
{
    if (this == &src)
        return (*this);
	this->_signed = src._signed;
    return (*this);
}

const std::string &Form::getName() const
{
	return (this->_name);
}

bool Form::getSigned() const
{
	return (this->_signed);
}

const int &Form::getSignG() const
{
	return (this->_sign_grade);
}

const int &Form::getExecG() const
{
	return (this->_exec_grade);
}

void Form::beSigned(Bureaucrat &_bt)
{
	if (_bt.getGrade() > this->_sign_grade)
		throw (Form::GradeTooLowException());
	this->_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &out, const Form &src)
{
	out << "name: " << src.getName() << std::endl;
	out << "signed: " << src.getSigned() << std::endl;
	out << "sign_grade: " << src.getSignG() << std::endl;
	out << "exec_grade: " << src.getExecG() << std::endl;
	return (out);
}
