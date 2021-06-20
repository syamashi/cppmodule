/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dotanuki.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:20:01 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/18 15:30:25 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dotanuki.hpp"

Dotanuki::Dotanuki() : AWeapon("Dotanuki", 3, 11)
{
}

Dotanuki::Dotanuki(Dotanuki const &src)
{
    *this = src;
}

Dotanuki::~Dotanuki()
{
}

void Dotanuki::attack() const
{
	std::cout << "* NYAHHHHHHHHHHHN! *" << std::endl;
}

Dotanuki& Dotanuki::operator=(const Dotanuki &src)
{
    if (this == &src)
        return (*this);
	this->name = src.getName();
	this->damage = src.getDamage();
	this->apcost = src.getDamage();
    return (*this);
}
