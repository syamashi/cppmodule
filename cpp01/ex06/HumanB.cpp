/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:11:17 by syamashi          #+#    #+#             */
/*   Updated: 2021/05/24 19:25:23 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
}

void	HumanB::setWeapon(Weapon &wp)
{
	this->ptr = &wp;
}

void	HumanB::attack()
{
	if (this->ptr)
		std::cout << this->name << " attacks with his " << this->ptr->getType() << std::endl;
	else
		std::cout << this->name << " attacks with his " << "hand" << std::endl;
}
