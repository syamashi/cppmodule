/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 11:55:09 by syamashi          #+#    #+#             */
/*   Updated: 2021/05/22 17:29:28 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

Zombie*	ZombieEvent::newZombie(std:: string name)
{
	Zombie	*ret;

	try
	{
		ret = new Zombie(name, this->type);
	}
	catch(std::bad_alloc)
	{
		std::cout << "bad_alloc" << std::endl;
		std::exit(1);
	}
	return ret;
};

void	ZombieEvent::setZombieType(const std::string& type)
{
	this->type = type;
};
