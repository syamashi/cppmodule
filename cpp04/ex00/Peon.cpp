/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:43:28 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/07 11:05:11 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

Peon::Peon(std::string name) : Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(const Peon &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

void	Peon::getPolymorphed() const
{
	//NAME has been turned into a pink pony!
	std::cout << this->name << " has been turned into a pink pony!" << std::endl;
}

Peon& Peon::operator=(Peon const &src)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this == &src)
        return (*this);
    this->name = src.name;
    return (*this);
}
