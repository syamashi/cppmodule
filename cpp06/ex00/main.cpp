/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 12:45:43 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/05 19:08:49 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "[usage] ./convert <value>" << std::endl;
		return 0;
	}
	try
	{
		Convert C(argv[1]);
	}
	catch (const std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
}
