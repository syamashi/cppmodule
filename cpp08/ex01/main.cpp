/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 08:05:44 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/27 19:00:15 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

template <typename T>
void pout(T const &mes)
{
	std::cout << std::endl << "----- " << mes << " -----" << std::endl;
}

int main()
{
	pout("subject");
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span sp2 = Span(20000);
	try
	{
		pout("sp2.shortestSpan()");
		std::cout << "_size: " << sp2.get_size() << std::endl;
		sp2.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		pout("sp2.longtestSpan()");
		sp2.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	pout("sp2.addNumber(1)");
	sp2.addNumber(1);
	std::cout << "_size: " << sp2.get_size() << std::endl;
	try
	{
		pout("sp2.shortestSpan()");
		sp2.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		pout("sp2.longestSpan()");
		sp2.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	pout("addNumber(3,5,...,39999)");
	for (int i = 3; i < 40000; i += 2)
	{
		sp2.addNumber(i);
	}
	std::cout << "_size: " << sp2.get_size() << std::endl;
	std::cout << "shortestSpan(): " << sp2.shortestSpan() << std::endl;
	std::cout << "longestSpan(): " << sp2.longestSpan() << std::endl;

	try
	{
		pout("addNumber(40001)");
		sp2.addNumber(40001);
		std::cout << "_size: " << sp2.get_size() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}
