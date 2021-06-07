/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 21:37:01 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/07 09:37:21 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : FragTrap("frag")
{

}

FragTrap::FragTrap(const std::string &name) : Name(name)
{
	std::cout << "[i]FragTrap " << name << " appear." << std::endl;
	this->Hit_points = 100;
	this->Max_hit_points = 100;
	this->Energy_points = 100;
	this->Max_energy_points = 100;
	this->Level = 1;
	this->Melee_attack_damage = 30;
	this->Ranged_attack_damage = 20;
	this->Armor_damage_reduction = 5;
}

FragTrap::FragTrap(const FragTrap &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

FragTrap::~FragTrap()
{
	std::cout << "[i]FragTrap " << this->Name << " broke." << std::endl;
}

void FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << this->Name << " attacks " << target << " at range, causing " << this->Ranged_attack_damage << " points of damage!" << std::endl;
}

void FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << this->Name << " attacks " << target << " at melee, causing " << this->Melee_attack_damage << " points of damage!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
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
	std::cout << "FR4G-TP " << this->Name << " received " << amount << " HP damage!!"
	<< " ([HP] " << this->Hit_points << " / " << this->Max_hit_points << ")" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (this->Hit_points + amount < this->Max_hit_points)
		this->Hit_points += amount;
	else
	{
		amount = this->Max_hit_points - this->Hit_points;
		this->Hit_points = this->Max_hit_points;
	}
	std::cout << "FR4G-TP " << this->Name << " repaired " << amount << " HP!!"
	<< " ([HP] " << this->Hit_points << " / " << this->Max_hit_points << ")" << std::endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	const std::string skills[] = {
		"wingardium leviosaaa",
		"alohomora",
		"Stupefy",
		"Obliviate",
		"Expecto Patronum"
	};
	int skillsize = 5;
	std::cout << "[" << this->Name << "] \"" << skills[rand() % skillsize] << "!!\"" << std::endl;

	if (this->Energy_points < 25)
	{
		std::cout << "but not enough EP!!"
		<< " ([EP] " << this->Energy_points << " / " << this->Max_energy_points << ")" << std::endl;
		return ;
	}
	this->Energy_points -= 25;
	std::cout << target << " received " << this->Ranged_attack_damage << " points of damage!"
	 << " ([EP] " << this->Energy_points << " / " << this->Max_energy_points << ")" << std::endl;
}

std::string FragTrap::get_Name() const
{
	return (this->Name);
}

FragTrap&	FragTrap::operator=(FragTrap const & src) {
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

std::ostream& operator<<(std::ostream& out, FragTrap const & src)
{
	out << "[" << src.get_Name() << "]" << "did you call me??";
	return (out);
}
