/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:20:13 by syamashi          #+#    #+#             */
/*   Updated: 2021/05/31 10:07:22 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion")
{
    std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(RadScorpion const &src)
{
    *this = src;
}

RadScorpion::~RadScorpion()
{
    std::cout << "* SPROTCH *" << std::endl;
}

void RadScorpion::takeDamage(int damage)
{
	if (damage < 0)
		damage = 0;
	if (this->hp < damage)
		this->hp = 0;
	else
		this->hp -= damage;
//	std::cout << damage << " HP of damage to the " << this->getType() << "!" << std::endl;
}

RadScorpion& RadScorpion::operator=(const RadScorpion &src)
{
    if (this == &src)
        return (*this);
    this->hp = src.getHp();
	this->type = src.getType();
    return (*this);
}

