/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 11:54:40 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/03 14:07:13 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(const std::string &name, const std::string &type)
{
	this->name = name;
	this->type = type;
}

Zombie::~Zombie()
{
	std::cout << "[i] " << this->name << " (" << this->type<< ") " << "died. You got " << rand() % 100 << " exp!" << std::endl;
}

void	Zombie::announce()
{
	std::cout << "<" << name << " (" << type << ")> " << "Braiiiiiiinnnssss..." << std::endl;
}

void	Zombie::set_stats(std::string& name, std::string& type)
{
	this->name = name;
	this->type = type;
}
