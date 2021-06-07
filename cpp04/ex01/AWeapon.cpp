/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:19:08 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/07 11:05:47 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon() : name("fist"), apcost(0), damage(0)
{
}

AWeapon::AWeapon(AWeapon const &src)
{
    *this = src;
}

AWeapon::AWeapon(std::string const & name, int apcost, int damage) : name(name), apcost(apcost), damage(damage)
{
}

AWeapon::~AWeapon()
{
}

std::string AWeapon::getName() const
{
	return (this->name);
}

int AWeapon::getAPcost() const
{
	return (this->apcost);
}

int AWeapon::getDamage() const
{
	return (this->damage);
}

AWeapon& AWeapon::operator=(const AWeapon &src)
{
    if (this == &src)
        return (*this);
	this->apcost = src.apcost;
	this->name = src.name;
	this->damage = src.damage;
    return (*this);
}

std::ostream& operator<<(std::ostream &out, AWeapon const &src)
{
	out << "name: " << src.getName() << std::endl;
	out << "apcost: " << src.getAPcost() << std::endl;
	out << "damage: " << src.getDamage() << std::endl;
	return (out);
}
