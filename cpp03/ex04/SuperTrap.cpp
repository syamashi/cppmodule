/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:58:45 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/18 13:16:50 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

void SuperTrap::debug()
{
	std::cout << "Hit_points: " << this->Hit_points << std::endl;
	std::cout << "Max_hit_points: " << this->Max_hit_points << std::endl;
	std::cout << "Energy_points: " << this->Energy_points << std::endl;
	std::cout << "Max_energy_points: " << this->Max_energy_points << std::endl;
	std::cout << "Level: " << this->Level << std::endl;
	std::cout << "Name: " << this->Name << std::endl;
	std::cout << "Melee_attack_damage: " << this->Melee_attack_damage << std::endl;
	std::cout << "Ranged_attack_damage: " << this->Ranged_attack_damage << std::endl;
	std::cout << "Armor_damage_reduction: " << this->Armor_damage_reduction << std::endl;
}

SuperTrap::SuperTrap()
{
}

SuperTrap::SuperTrap(const std::string &name) : ClapTrap(name), FragTrap(name), NinjaTrap(name)
{
	std::cout << "[i]SuperTrap " << name << " appear." << std::endl;
	this->Hit_points = 100;
	this->Max_hit_points = 100;
	this->Energy_points = 120;
	this->Max_energy_points = 120;
	this->Level = 1;
	this->Melee_attack_damage = 60;
	this->Ranged_attack_damage = 20;
	this->Armor_damage_reduction = 5;
	debug();
}

SuperTrap::SuperTrap(SuperTrap const &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

SuperTrap::~SuperTrap()
{
	std::cout << "[i]SuperTrap " << this->Name << " broke." << std::endl;
}

void SuperTrap::rangedAttack(const std::string &target)
{
	FragTrap::rangedAttack(target);
}

void SuperTrap::meleeAttack(const std::string &target)
{
	NinjaTrap::meleeAttack(target);
}

SuperTrap& SuperTrap::operator=(const SuperTrap &src)
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

std::ostream& operator<<(std::ostream &out, SuperTrap const &src)
{
	out << "[" << src.get_Name() << "]" << "3 minitus passed??";
	return (out);
}
