/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 11:37:59 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/07 12:58:05 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "---new Bureaucrat(boss, 1)---" << std::endl;
	Bureaucrat *boss = new Bureaucrat("boss", 1);
	std::cout << *boss << std::endl;

	std::cout << "---boss->incG();---" << std::endl;
	try
	{
		boss->incG();
	}
	catch(const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	std::cout << "---boss->decG();---" << std::endl;
	boss->decG();
	std::cout << *boss << std::endl;

	std::cout << "---boss->decG();---" << std::endl;
	boss->decG();
	std::cout << *boss << std::endl;

	std::cout << "---boss->decG();---" << std::endl;
	boss->decG();
	std::cout << *boss << std::endl;

	std::cout << "---new Bureaucrat(baby, 150)---" << std::endl;
	Bureaucrat *baby = new Bureaucrat("baby", 150);
	std::cout << *baby << std::endl;

	std::cout << "---baby->decG();---" << std::endl;
	try
	{
		baby->decG();
	}
	catch(const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	std::cout << "---baby->incG();---" << std::endl;
	baby->incG();
	std::cout << *baby << std::endl;

	std::cout << "---baby->incG();---" << std::endl;
	baby->incG();
	std::cout << *baby << std::endl;

	std::cout << "---baby->incG();---" << std::endl;
	baby->incG();
	std::cout << *baby << std::endl;

	std::cout << "---new Bureaucrat(babyy, 151)---" << std::endl;
	try
	{
		Bureaucrat *babyy = new Bureaucrat("babyy", 151);
		delete babyy;
	}
	catch(const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	std::cout << "---new Bureaucrat(bosss, 0)---" << std::endl;
	try
	{
		Bureaucrat *bosss = new Bureaucrat("bosss", 0);
		delete bosss;
	}
	catch(const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	delete boss;
	delete baby;
	return (0);
}
