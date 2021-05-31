/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 22:12:27 by syamashi          #+#    #+#             */
/*   Updated: 2021/05/22 17:29:31 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(std::string s)
{
	str = s;
};

void Pony::ponyout()
{
	std::cout << str << std::endl;
}

void ponyOnTheHeap()
{
	Pony *heap;

	try
	{
		heap = new Pony("I'M HEAP PONY!");
	}
	catch(std::bad_alloc){
		std::cout << "bad_alloc" << std::endl;
		std::exit(1);
	}
	heap->ponyout();
	delete heap;
};

void ponyOnTheStack()
{
	Pony stack("i'm stack pony...");

	stack.ponyout();
};
