/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 11:37:59 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/23 13:24:58 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void pout(const std::string &mes)
{
	std::cout << std::endl << " --- " << mes << " --- " << std::endl;
}

int main()
{
	srand(time(NULL));

	Bureaucrat *mr138 = new Bureaucrat("mr138", 138);
	Bureaucrat *mr137 = new Bureaucrat("mr137", 137);
	Bureaucrat *mr46 = new Bureaucrat("mr46", 46);
	Bureaucrat *mr45 = new Bureaucrat("mr45", 45);
	Bureaucrat *mr6 = new Bureaucrat("mr6", 6);
	Bureaucrat *mr5 = new Bureaucrat("mr5", 5);

	pout("new ShrubberyCreationForm(shr)");
	ShrubberyCreationForm *shr = new ShrubberyCreationForm("shr"); //低木
	std::cout << *shr;

	pout("new RobotomyRequestForm(rbt)");
	RobotomyRequestForm *rbt = new RobotomyRequestForm("rbt");
	std::cout << *rbt;

	pout("new PresidentialPardonForm(prs)");
	PresidentialPardonForm *prs = new PresidentialPardonForm("prs");
	std::cout << *prs;

	pout("mr137->executeForm(*shr)");
	mr137->executeForm(*shr);
	pout("mr138->signForm(*shr)");
	mr138->signForm(*shr);
	std::cout << *shr << std::endl;
	pout("mr138->signForm(*shr)");
	mr138->executeForm(*shr);
	pout("mr137->executeForm(*shr)");
	mr137->executeForm(*shr);

	pout("mr45->executeForm(*rbt)");
	mr45->executeForm(*rbt);
	pout("mr46->signForm(*rbt)");
	mr46->signForm(*rbt);
	std::cout << *rbt << std::endl;
	pout("mr46->executeForm(*rbt)");
	mr46->executeForm(*rbt);

	pout("mr45->executeForm(*rbt)");
	mr45->executeForm(*rbt);
	mr45->executeForm(*rbt);
	mr45->executeForm(*rbt);
	mr45->executeForm(*rbt);
	mr45->executeForm(*rbt);

	pout("mr5->executeForm(*prs)");
	mr5->executeForm(*prs);

	pout("mr6->signForm(*prs)");
	mr6->signForm(*prs);
	std::cout << *prs << std::endl;

	pout("mr6->executeForm(*prs)");
	mr6->executeForm(*prs);

	pout("mr5->executeForm(*prs)");
	mr5->executeForm(*prs);

	delete mr138;
	delete mr137;
	delete mr46;
	delete mr45;
	delete mr6;
	delete mr5;
	delete shr;
	delete rbt;
	delete prs;
	return (0);
}
