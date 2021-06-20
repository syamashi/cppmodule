/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:50:05 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/18 15:08:19 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"
#include "Sorcerer.hpp"
#include "Victim.hpp"

void pout(std::string mes)
{
	std::cout << std::endl << "----- " << mes << " -----" << std::endl;
}

int main()
{
	Sorcerer robert("Robert", "the Magnificent");

	Victim jim("Jimmy");
	Peon joe("Joe");

	std::cout << robert << jim << joe;

	robert.polymorph(jim);
	robert.polymorph(joe);

//	Sorcerer emp();  error: empty parentheses interpreted as a function declaration
	pout("Victim jim.getPolymophed()");
	jim.getPolymorphed();
	pout("Peon joe.getPolymophed()");
	joe.getPolymorphed();
	pout("destructer");

	return 0;
}
