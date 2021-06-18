/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 21:37:01 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/18 12:31:32 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
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

void FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	const std::string skills[] = {
		"wingardium leviosaaa",
		"alohomora",
		"Stupefy",
		"Obliviate",
		"Expecto Patronum"
	};
	if (this->Energy_points < 25)
	{
		std::cout << "not enough EP!"
		<< " ([EP] " << this->Energy_points << " / " << this->Max_energy_points << ")" << std::endl;
		return ;
	}

	int skillsize = 5;
	std::cout << "[" << this->Name << "] \"" << skills[rand() % skillsize] << "!!\"" << std::endl;

	this->Energy_points -= 25;
	std::cout << target << " received " << this->Ranged_attack_damage << " points of damage!"
	 << " ([EP] " << this->Energy_points << " / " << this->Max_energy_points << ")" << std::endl;
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
