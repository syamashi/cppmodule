/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 21:37:01 by syamashi          #+#    #+#             */
/*   Updated: 2021/05/29 10:59:39 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : ClapTrap("cherry")
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
