/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 13:58:53 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/21 08:51:01 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("boss"), _grade(1)
{
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
    *this = src;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &src)
{
    if (this == &src)
        return (*this);
	this->_grade = src._grade;
    return (*this);
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incG()
{
	if (this->_grade == 1)
		throw (Bureaucrat::GradeTooHighException());
	--this->_grade;
}

void Bureaucrat::decG()
{
	if (this->_grade == 150)
		throw (Bureaucrat::GradeTooLowException());
	++this->_grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() // throwを投げると、what()の中に文字列を入れる
{
	return ("Grade is too low");
}

std::ostream& operator<<(std::ostream& out, Bureaucrat const& src)
{
	//<name>, bureaucrat grade <grade>.
	out << src.getName() << ", bureaucrat grade "  << src.getGrade() << "." << std::endl;
	return (out);
}
