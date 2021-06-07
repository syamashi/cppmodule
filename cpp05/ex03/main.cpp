/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 11:37:59 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/07 13:12:48 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

void pout(const std::string &mes)
{
	std::cout << "--- " << mes << " ---" << std::endl;
}

int main()
{
	srand(time(NULL));
	Intern someRandomIntern;
	Form* rrf;
	Form* pf;
	Form* sf;

	pout("someRandomIntern.makeForm(robotomy request, Bender)");
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << *rrf << std::endl;
	pout("someRandomIntern.makeForm(shrubbery creation, home)");
	sf = someRandomIntern.makeForm("shrubbery creation", "home");
	std::cout << *sf << std::endl;
	pout("someRandomIntern.makeForm(presidential pardon, bunjiro)");
	pf = someRandomIntern.makeForm("presidential pardon", "bunjiro");
	std::cout << *pf << std::endl;
	pout("someRandomIntern.makeForm(aaaa,aaaa)");
	try
	{
		Form *ef = someRandomIntern.makeForm("aaaa", "aaaa");
		std::cout << *ef << std::endl;
		delete ef;
	}
	catch(const std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}

	delete rrf;
	delete pf;
	delete sf;

	return (0);
}
