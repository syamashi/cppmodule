/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:20:13 by syamashi          #+#    #+#             */
/*   Updated: 2021/05/31 10:07:19 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant")
{
    std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const &src)
{
    *this = src;
}

SuperMutant::~SuperMutant()
{
    std::cout << "Aaargh..." << std::endl;
}

void SuperMutant::takeDamage(int damage)
{
	damage -= 3;
	if (damage < 0)
		damage = 0;
	if (this->hp < damage)
		this->hp = 0;
	else
		this->hp -= damage;
//	std::cout << damage << " HP of damage to the " << this->getType() << "!" << std::endl;
}

SuperMutant& SuperMutant::operator=(const SuperMutant &src)
{
    if (this == &src)
        return (*this);
    this->hp = src.getHp();
	this->type = src.getType();
    return (*this);
}
