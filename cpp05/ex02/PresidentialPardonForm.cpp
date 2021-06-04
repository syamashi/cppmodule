/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 08:01:16 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/04 12:06:56 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: PresidentialPardonForm("target")
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src)
{
    *this = src;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
: Form("PresidentialPardonForm", 25, 5, target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
    if (this == &src)
        return (*this);
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw (Form::NotSignedException());
	if (executor.getGrade() > this->getExecG())
		throw (Form::GradeTooLowException());
	// Tells us <target> has been pardoned by Zafod Beeblebrox
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
