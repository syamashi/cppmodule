/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 08:01:16 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/04 09:23:26 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
: RobotomyRequestForm("target")
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src)
{
    *this = src;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
: Form("RobotomyRequestForm", 72, 45, target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
    if (this == &src)
        return (*this);
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw (Form::NotSignedException());
	if (executor.getGrade() > this->getExecG())
		throw (Form::GradeTooLowException());
	if (rand() % 2)
	{
		std::cout << "* DRRRRRRRRRRRRRRRRRRRR!! *" << std::endl;
		//<target> has been robotomized
		std::cout << this->getTarget() << " has been robotomized" << std::endl;
	}
	else
		std::cout << "Failed to robotomized " << this->getTarget() << "." << std::endl;
}
