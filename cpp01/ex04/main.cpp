/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 17:33:06 by syamashi          #+#    #+#             */
/*   Updated: 2021/05/22 17:38:05 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>

int main()
{
	std::string	s;
	std::string*	ptr = &s;
	std::string&	ref = s;

	s = "HI THIS IS BRAIN";
	std::cout << std::setfill(' ') << std::setw(5) << "s:";
	std::cout << s << std::endl;
	std::cout << std::setfill(' ') << std::setw(5) << "*ptr:";
	std::cout << *ptr << std::endl;
	std::cout << std::setfill(' ') << std::setw(5) << "ref:";
	std::cout << ref << std::endl;
	return (0);
}
