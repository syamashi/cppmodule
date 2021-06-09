/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 09:59:04 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/09 09:39:44 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
void pout(const T &mes)
{
	std::cout << std::endl << " ----- " << mes << " ----- " << std::endl;
}

int main()
{
	try
	{
		pout("empty[0] = 1");
		Array<int> empty;
		empty[0] = 1;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		pout("empty[-1] = 1");
		Array<int> empty;
		empty[-1] = 1;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		pout("copy = empty, copy[0]");
		Array<int> empty;
		Array<int> copy = empty;
		copy[0] = 1;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		pout("Array<int> ints(3)");
		Array<int> ints(3);
		for (int i = 0; i < 3; ++i)
		{
			ints[i] = i + 10;
			std::cout << "ints[" << i << "]:" << ints[i] << std::endl;
		}


		pout("Array<int> copy(3)");
		Array<int> copy(ints);
		for (int i = 0; i < 3; ++i)
		{
			ints[i] = i + 10;
			std::cout << "copy[" << i << "]:" << copy[i] << std::endl;
		}
		pout("copy.size()");
		std::cout << copy.size() << std::endl;

		pout("Array<int> equal(3)");
		Array<int> equal = copy;
		for (int i = 0; i < 3; ++i)
		{
			ints[i] = i + 10;
			std::cout << "equal[" << i << "]:" << equal[i] << std::endl;
		}
		pout("equal.size()");
		std::cout << equal.size() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}
