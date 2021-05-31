/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:09:47 by syamashi          #+#    #+#             */
/*   Updated: 2021/05/24 10:47:52 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human()
{
	try
	{
		this->br = new Brain;
	}
	catch(std::bad_alloc)
	{
		std::cout << "bad_alloc" << std::endl;
	}
}

Human::~Human()
{
	std::cout << "[~Human] died" << std::endl;
	delete this->br;
}

std::string Human::identify()
{
	return (this->br->identify());
}

Brain& Human::getBrain()
{
	return (*this->br);
}
