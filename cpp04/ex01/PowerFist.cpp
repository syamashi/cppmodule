/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:20:05 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/18 15:30:22 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50)
{
}

PowerFist::PowerFist(PowerFist const &src)
{
    *this = src;
}

PowerFist::~PowerFist()
{
}

PowerFist& PowerFist::operator=(const PowerFist &src)
{
    if (this == &src)
        return (*this);
    this->name = src.getName();
	this->damage = src.getDamage();
	this->apcost = src.getAPcost();
    return (*this);
}

void PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
