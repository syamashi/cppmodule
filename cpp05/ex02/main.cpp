/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 11:37:59 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/04 12:09:26 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void pout(const std::string &mes)
{
	std::cout << "--- " << mes << " ---" << std::endl;
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
	std::cout << *shr << std::endl;

	pout("new RobotomyRequestForm(rbt)");
	RobotomyRequestForm *rbt = new RobotomyRequestForm("rbt");
	std::cout << *rbt << std::endl;

	pout("new PresidentialPardonForm(prs)");
	PresidentialPardonForm *prs = new PresidentialPardonForm("prs");
	std::cout << *prs << std::endl;

	pout("shr->execute(*mr137)");
	try
	{
		shr->execute(*mr137);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
	pout("shr->beSigned(mr138)");
	shr->beSigned(*mr138);
	std::cout << *shr << std::endl;
	pout("shr->execute(*mr138)");
	try
	{
		shr->execute(*mr138);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
	pout("shr->execute(*mr137)");
	shr->execute(*mr137);
	std::cout << "is there <shr_shrubbery> file?" << std::endl << std::endl;

	pout("rbt->execute(*mr45)");
	try
	{
		rbt->execute(*mr45);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
	pout("rbt->beSigned(mr46)");
	rbt->beSigned(*mr46);
	std::cout << *rbt << std::endl;
	pout("rbt->execute(*mr46)");
	try
	{
		rbt->execute(*mr46);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
	pout("rbt->execute(*mr45)");
	rbt->execute(*mr45);
	rbt->execute(*mr45);
	rbt->execute(*mr45);
	rbt->execute(*mr45);
	rbt->execute(*mr45);

	pout("prs->execute(*mr5)");
	try
	{
		prs->execute(*mr5);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
	pout("prs->beSigned(mr6)");
	prs->beSigned(*mr6);
	std::cout << *prs << std::endl;
	pout("prs->execute(*mr6)");
	try
	{
		prs->execute(*mr6);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
	pout("prs->execute(*mr5)");
	prs->execute(*mr5);

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
