/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 08:55:23 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/22 11:50:32 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename T>
void arr_out(const T &a)
{
	std::cout << a << " ";
}

template<typename T>
void pout(const T &a)
{
	std::cout << std::endl << " -------- " << a << " -------- " << std::endl;
}

int main()
{
	pout("ints[] = {0, 1, 2, 3, 4}");
	int ints[] = {0, 1, 2, 3, 4};
	::iter(ints, 5, arr_out);

	pout("chars[] = {'a', 'b', 'c', 'd', 'e'}");
	char chars[] = {'a', 'b', 'c', 'd', 'e'};
	::iter(chars, 5, arr_out);

	pout("strs[] = {I, like, sushi, sushisushi}");
	std::string strs[] = {"I", "like", "sushi", "sushisushi"};
	::iter(strs, 4, arr_out);
}
