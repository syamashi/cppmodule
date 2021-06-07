/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 21:37:01 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/07 10:25:40 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap()
{
}

NinjaTrap::NinjaTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "[i]NinjaTrap " << name << " appear." << std::endl;
	this->Hit_points = 60;
	this->Max_hit_points = 60;
	this->Energy_points = 120;
	this->Max_energy_points = 120;
	this->Level = 1;
	this->Melee_attack_damage = 60;
	this->Ranged_attack_damage = 5;
	this->Armor_damage_reduction = 0;
}

NinjaTrap::NinjaTrap(NinjaTrap const &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "[i]NinjaTrap " << this->Name << " broke." << std::endl;
}

void NinjaTrap::rangedAttack(std::string const & target)
{
	std::cout << "N1NJ-TP " << this->Name << " attacks " << target << " at range, causing " << this->Ranged_attack_damage << " points of damage!" << std::endl;
}

void NinjaTrap::meleeAttack(std::string const & target)
{
	std::cout << "N1NJ-TP " << this->Name << " attacks " << target << " at melee, causing " << this->Melee_attack_damage << " points of damage!" << std::endl;
}

void NinjaTrap::takeDamage(unsigned int amount)
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
	std::cout << "N1NJ-TP " << this->Name << " received " << amount << " HP damage!!"
	<< " ([HP] " << this->Hit_points << " / " << this->Max_hit_points << ")" << std::endl;
}

void NinjaTrap::beRepaired(unsigned int amount)
{
	if (this->Hit_points + amount < this->Max_hit_points)
		this->Hit_points += amount;
	else
	{
		amount = this->Max_hit_points - this->Hit_points;
		this->Hit_points = this->Max_hit_points;
	}
	std::cout << "N1NJ-TP " << this->Name << " repaired " << amount << " HP!!"
	<< " ([HP] " << this->Hit_points << " / " << this->Max_hit_points << ")" << std::endl;
}

void NinjaTrap::ninjaShoebox(ScavTrap &scav)
{
	if (this->Energy_points < 25)
	{
		std::cout << this->Name << " tried to attck " << scav.get_Name() << ". but not enough EP!!"
		 " ([EP] " << this->Energy_points << " / " << this->Max_energy_points << ")" << std::endl;
		return ;
	}
	this->Energy_points -= 25;
	const std::string ninjas[] = {
		"katon",
		"suiton",
		"doton",
		"kumogakure",
		"shuriken"
	};
	int skillsize = 5;
	std::cout << "N1NJ-TP " << this->Name << " attacks " << scav.get_Name() << " \"" << ninjas[rand() % skillsize] << "!!\" causing " << this->Melee_attack_damage << " points of damage!"
	 << " ([EP] " << this->Energy_points << " / " << this->Max_energy_points << ")" << std::endl;
	scav.takeDamage(this->Melee_attack_damage);
}

void NinjaTrap::ninjaShoebox(FragTrap &flag)
{
	if (this->Energy_points < 25)
	{
		std::cout << this->Name << " tried to attck " << flag.get_Name() << ". but not enough EP!!"
		 " ([EP] " << this->Energy_points << " / " << this->Max_energy_points << ")" << std::endl;
		return ;
	}
	this->Energy_points -= 25;
	const std::string ninjas[] = {
		"katon",
		"suiton",
		"doton",
		"kumogakure",
		"shuriken"
	};
	int skillsize = 5;
	std::cout << "N1NJ-TP " << this->Name << " attacks " << flag.get_Name() << " \"" << ninjas[rand() % skillsize] << "!!\" causing " << this->Melee_attack_damage << " points of damage!"
	 << " ([EP] " << this->Energy_points << " / " << this->Max_energy_points << ")" << std::endl;
	flag.takeDamage(this->Melee_attack_damage);
}

void NinjaTrap::ninjaShoebox(NinjaTrap &ninja)
{
	if (this->Energy_points < 25)
	{
		std::cout << this->Name << " tried to attck " << ninja.get_Name() << ". but not enough EP!!"
		 " ([EP] " << this->Energy_points << " / " << this->Max_energy_points << ")" << std::endl;
		return ;
	}
	this->Energy_points -= 25;
	const std::string ninjas[] = {
		"katon",
		"suiton",
		"doton",
		"kumogakure",
		"shuriken"
	};
	int skillsize = 5;
	std::cout << "N1NJ-TP " << this->Name << " attacks " << ninja.get_Name() << " \"" << ninjas[rand() % skillsize] << "!!\" causing " << this->Melee_attack_damage << " points of damage!"
	 << " ([EP] " << this->Energy_points << " / " << this->Max_energy_points << ")" << std::endl;
	ninja.takeDamage(this->Melee_attack_damage);
}

NinjaTrap& NinjaTrap::operator=(const NinjaTrap &src)
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

std::ostream& operator<<(std::ostream& out, NinjaTrap const & src)
{
	out << "[" << src.get_Name() << "]" << "aieeee!! ninja!? ninjanande!?";
	return (out);
}
