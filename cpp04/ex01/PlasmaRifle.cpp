/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:20:01 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/18 15:30:25 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21)
{
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &src)
{
    *this = src;
}

PlasmaRifle::~PlasmaRifle()
{
}

void PlasmaRifle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}

PlasmaRifle& PlasmaRifle::operator=(const PlasmaRifle &src)
{
    if (this == &src)
        return (*this);
	this->name = src.getName();
	this->damage = src.getDamage();
	this->apcost = src.getDamage();
    return (*this);
}
