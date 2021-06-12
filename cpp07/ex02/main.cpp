/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 09:59:04 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/13 08:46:29 by syamashi         ###   ########.fr       */
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
		std::cout << "ints.size(): " << ints.size() << std::endl;

		pout("Array<int> copy(3)");
		Array<int> copy(ints);
		for (int i = 0; i < 3; ++i)
		{
			ints[i] = i + 10;
			std::cout << "copy[" << i << "]:" << copy[i] << std::endl;
		}
		std::cout << "copy.size(): " << copy.size() << std::endl;

		pout("Array<int> equal(3)");
		Array<int> equal = copy;
		for (int i = 0; i < 3; ++i)
		{
			ints[i] = i + 10;
			std::cout << "equal[" << i << "]:" << equal[i] << std::endl;
		}
		std::cout << "equal.size(): " << equal.size() << std::endl;

		pout("equal[1] = [0], [2] = [0]");
		for (int i = 1; i < 3; ++i)
			equal[i] = equal[0];
		for (int i = 0; i < 3; ++i)
		{
			ints[i] = i + 10;
			std::cout << "equal[" << i << "]:" << equal[i] << std::endl;
		}
		std::cout << "equal.size(): " << equal.size() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}
