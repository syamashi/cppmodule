/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 21:37:01 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/18 12:37:45 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : Name("clap")
{
}

ClapTrap::ClapTrap(const std::string &name) : Name(name)
{
	std::cout << "[i]ClapTrap " << name << " appear." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

ClapTrap::~ClapTrap()
{
	std::cout << "[i]ClapTrap " << this->Name << " broke." << std::endl;
}

std::string ClapTrap::get_Name() const
{
	return (this->Name);
}

void ClapTrap::rangedAttack(std::string const & target)
{
	std::cout << this->Name << " attacks " << target << " at range, causing " << this->Ranged_attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::meleeAttack(std::string const & target)
{
	std::cout << this->Name << " attacks " << target << " at melee, causing " << this->Melee_attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > this->Armor_damage_reduction)
		amount -= this->Armor_damage_reduction;
	else
		amount = 0;
	if (this->Hit_points > amount)
		this->Hit_points -= amount;
	else
	{
		amount = this->Hit_points;
		this->Hit_points = 0;
	}
	std::cout << this->Name << " received " << amount << " HP damage!!"
	<< " ([HP] " << this->Hit_points << " / " << this->Max_hit_points << ")" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->Hit_points + amount < this->Max_hit_points)
		this->Hit_points += amount;
	else
	{
		amount = this->Max_hit_points - this->Hit_points;
		this->Hit_points = this->Max_hit_points;
	}
	std::cout << this->Name << " repaired " << amount << " HP!!"
	<< " ([HP] " << this->Hit_points << " / " << this->Max_hit_points << ")" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this == &src)
 		return (*this);
	this->Hit_points = src.Hit_points;
	this->Max_hit_points = src.Max_hit_points;
	this->Energy_points = src.Energy_points;
	this->Max_energy_points = src.Max_energy_points;
	this->Level = src.Level;
	this->Melee_attack_damage = src.Melee_attack_damage;
	this->Ranged_attack_damage = src.Ranged_attack_damage;
	this->Armor_damage_reduction = src.Armor_damage_reduction;
    return (*this);
}

std::ostream& operator<<(std::ostream& out, ClapTrap const & src)
{
	out << "[" << src.get_Name() << "]" << "did you call me??";
	return (out);
}
