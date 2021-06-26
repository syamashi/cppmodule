/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 12:32:19 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/24 09:46:39 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &src)
{
    *this = src;
}

Intern::~Intern()
{
}

Intern& Intern::operator=(const Intern &src)
{
    if (this == &src)
        return (*this);
    return (*this);
}

Form *Intern::InternShrubbery(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

Form *Intern::InternRobotomy(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

Form *Intern::InternPresidential(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

Form *Intern::makeForm(const std::string &name, const std::string &target)
{
	std::string names[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	Form* (Intern::*func[])(const std::string &) = {
		&Intern::InternShrubbery,
		&Intern::InternRobotomy,
		&Intern::InternPresidential
	};
	for (int i = 0; i < 3; i++)
	{
		if (names[i] == name)
			return ((this->*(func[i]))(target));
	}
	throw (NotMatchNameException());
}

const char *Intern::NotMatchNameException::what() const throw()
{
	return ("does not match name.");
}
