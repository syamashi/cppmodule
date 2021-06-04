/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 11:37:59 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/03 17:09:29 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "---new Form(ringi, 100, 50)---" << std::endl;
	Form *ringi = new Form("ringi", 100, 50);
	std::cout << *ringi << std::endl;
	Bureaucrat *mr100 = new Bureaucrat("mr100", 100);
	Bureaucrat *mr101 = new Bureaucrat("mr101", 101);

	std::cout << "---mr101->signForm(*ringi)---" << std::endl;
	mr101->signForm(*ringi);
	std::cout << *ringi << std::endl;
	std::cout << "---mr100->signForm(*ringi)---" << std::endl;
	mr100->signForm(*ringi);
	std::cout << *ringi << std::endl;

	try
	{
		std::cout << "---new Form(ringi151a, 151, 50)---" << std::endl;
		Form *ringi151a = new Form("ringi151a", 151, 50);
		delete ringi151a;
	}
	catch(const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	try
	{
		std::cout << "---new Form(ringi151b, 100, 151)---" << std::endl;
		Form *ringi151b = new Form("ringi151b", 100, 151);
		delete ringi151b;
	}
	catch(const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	try
	{
		std::cout << "---new Form(ringi0a, 0, 50)---" << std::endl;
		Form *ringi0a = new Form("ringi0a", 0, 50);
		delete ringi0a;
	}
	catch(const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	try
	{
		std::cout << "---new Form(ringi0b, 100, 0)---" << std::endl;
		Form *ringi0b = new Form("ringi0b", 100, 0);
		delete ringi0b;
	}
	catch(const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	delete ringi;
	delete mr100;
	delete mr101;
	return (0);
}
