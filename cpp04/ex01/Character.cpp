/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:19:28 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/07 11:04:01 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("name"), ap(0), aweapon(NULL)
{
}

Character::Character(std::string const & name) : name(name), ap(40), aweapon(NULL)
{
}

Character::Character(Character const &src)
{
    *this = src;
}

Character::~Character()
{
}

void Character::recoverAP()
{
	if (this->ap < 31)
		this->ap += 10;
	else
		this->ap = 40;
}

void Character::equip(AWeapon *aweapon)
{
	this->aweapon = aweapon;
}

void Character::attack(Enemy *enemy)
{
	if (!enemy)
		return ;
	if (!this->aweapon)
	{
		std::cout << this->name << " has no aweapon..." << std::endl;
		return ;
	}
	if (this->ap < this->aweapon->getAPcost())
	{
		std::cout << this->name << " has not enough AP..." << std::endl;
		return ;
	}
	std::cout << this->name << " attacks " << enemy->getType() << " with a " << this->aweapon->getName() << std::endl;
	this->aweapon->attack();
	this->ap -= this->aweapon->getAPcost();
	enemy->takeDamage(this->aweapon->getDamage());
	if (enemy->getHp() == 0)
		delete enemy;
}

int Character::getAp() const
{
	return (this->ap);
}

std::string Character::getName() const
{
	return (this->name);
}

std::string Character::getAweaponName() const
{
	if (!this->aweapon)
		return ("fist");
	return (this->aweapon->getName());
}

std::ostream& operator<<(std::ostream &out, Character const &src)
{
	std::string weapon_name;

	weapon_name = src.getAweaponName();
	out << src.getName() << " has " << src.getAp() << " AP and ";
	if (weapon_name == "fist")
		out << "is unarmed" << std::endl;
	else
		out << "wields a " << weapon_name << std::endl;
	return (out);
}

Character& Character::operator=(const Character &src)
{
    if (this == &src)
        return (*this);
	this->name = src.getName();
	this->ap = src.getAp();
    return (*this);
}