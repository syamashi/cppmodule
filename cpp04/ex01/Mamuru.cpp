/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mamuru.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:20:13 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/20 21:36:59 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mamuru.hpp"

Mamuru::Mamuru() : Enemy(10, "Mamuru")
{
    std::cout << "* WAON! *" << std::endl;
}

Mamuru::Mamuru(Mamuru const &src)
{
    *this = src;
}

Mamuru::~Mamuru()
{
    std::cout << "* TIUN TIUN TIUN *" << std::endl;
}

void Mamuru::takeDamage(int damage)
{
	if (damage < 0)
		damage = 0;
	if (this->hp < damage)
		this->hp = 0;
	else
		this->hp -= damage;
//	std::cout << damage << " HP of damage to the " << this->getType() << "!" << std::endl;
}

Mamuru& Mamuru::operator=(const Mamuru &src)
{
    if (this == &src)
        return (*this);
    this->hp = src.getHp();
	this->type = src.getType();
    return (*this);
}

