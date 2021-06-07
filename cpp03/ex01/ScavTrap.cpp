/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 21:37:01 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/07 10:23:13 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : Name("scav")
{
}

ScavTrap::ScavTrap(const std::string &name) : Name(name)
{
	std::cout << "[i]ScavTrap " << name << " appear." << std::endl;
	this->Hit_points = 100;
	this->Max_hit_points = 100;
	this->Energy_points = 50;
	this->Max_energy_points = 50;
	this->Level = 1;
	this->Melee_attack_damage = 20;
	this->Ranged_attack_damage = 15;
	this->Armor_damage_reduction = 3;
}

ScavTrap::ScavTrap(ScavTrap const &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

ScavTrap::~ScavTrap()
{
	std::cout << "[i]ScavTrap " << this->Name << " broke." << std::endl;
}

void ScavTrap::rangedAttack(std::string const & target)
{
	std::cout << "SC4V-TP " << this->Name << " attacks " << target << " at range, causing " << this->Ranged_attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::meleeAttack(std::string const & target)
{
	std::cout << "SC4V-TP " << this->Name << " attacks " << target << " at melee, causing " << this->Melee_attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
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
	std::cout << "SC4V-TP " << this->Name << " received " << amount << " HP damage!!"
	<< " ([HP] " << this->Hit_points << " / " << this->Max_hit_points << ")" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (this->Hit_points + amount < this->Max_hit_points)
		this->Hit_points += amount;
	else
	{
		amount = this->Max_hit_points - this->Hit_points;
		this->Hit_points = this->Max_hit_points;
	}
	std::cout << "SC4V-TP " << this->Name << " repaired " << amount << " HP!!"
	<< " ([HP] " << this->Hit_points << " / " << this->Max_hit_points << ")" << std::endl;
}

void ScavTrap::challengeNewcomer(std::string const & target)
{
	if (this->Energy_points < 25)
	{
		std::cout << this->Name << " tried to order challenge " << target << ". but not enough EP!!"
		 " ([EP] " << this->Energy_points << " / " << this->Max_energy_points << ")" << std::endl;
		return ;
	}
	this->Energy_points -= 25;
	const std::string challenges[] = {
		"Do push-ups",
		"Do sit-ups",
		"Run over",
		"Do back extensions",
		"Do Squat"
	};
	int skillsize = 5;
	std::cout << "SC4V-TP " << this->Name << " order " << target << " to a challenge: \"" << challenges[rand() % skillsize]
	 << "!!\" ([EP] " << this->Energy_points << " / " << this->Max_energy_points << ")" << std::endl;
}

std::string ScavTrap::get_Name() const
{
	return (this->Name);
}

ScavTrap&	ScavTrap::operator=(ScavTrap const & src) {
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

std::ostream& operator<<(std::ostream &out, ScavTrap const &src)
{
	out << "[" << src.get_Name() << "]" << "kayu.... uma....";
	return (out);
}
