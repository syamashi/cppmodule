/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:47:48 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/09 12:56:13 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <iostream>

template <typename T>
void pout(const T &mes)
{
	std:: cout << " ----- " << mes << " ----- " << std::endl;
}

int main()
{
	std::vector<int> I;
	for (int i = 0; i < 20; ++i)
		I.push_back(i % 10);
	std::vector<int>::iterator it = easyfind(I, 5);
}