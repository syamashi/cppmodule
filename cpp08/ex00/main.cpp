/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:47:48 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/09 15:35:31 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
void pout(const T &mes)
{
	std::cout << std::endl << " ----- " << mes << " ----- " << std::endl;
}

int main()
{
	try
	{
		std::vector<int> I(0);
		for (int i = 0; i < 20; ++i)
			I.push_back(i % 10);
		pout("easyfind(I, 0)");
		std::vector<int>::iterator it = easyfind(I, 0);
		std::cout << "I[" << it - I.begin() << "]" << std::endl;
		pout("easyfind(I, 5)");
		it = easyfind(I, 5);
		std::cout << "I[" << it - I.begin() << "]" << std::endl;
		pout("easyfind(I, 10)");
		it = easyfind(I, 10);
		std::cout << "I[" << it - I.begin() << "]" << std::endl;
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
}
