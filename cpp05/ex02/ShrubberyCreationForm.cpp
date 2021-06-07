/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 08:01:16 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/04 09:23:26 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
: Form("ShrubberyCreationForm", 145, 137, "target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src)
{
    *this = src;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
: Form("ShrubberyCreationForm", 145, 137, target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    if (this == &src)
        return (*this);
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw (Form::NotSignedException());
	if (executor.getGrade() > this->getExecG())
		throw (Form::GradeTooLowException());

	std::string buf = "tree > " + this->getTarget() + "_shrubbery";
	const char *exectree = buf.c_str();
	try
	{
		system(exectree);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}
