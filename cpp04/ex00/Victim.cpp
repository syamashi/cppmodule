/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:33:47 by syamashi          #+#    #+#             */
/*   Updated: 2021/05/28 17:21:56 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim()
{
    std::cout << "Default constructor called" << std::endl;
}

Victim::Victim(const std::string &name) : name(name)
{
	//Some random victim called NAME just appeared!
	std::cout << "Some random victim called " << this->name << " just appeared!" << std::endl;
}

Victim::Victim(Victim const &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Victim::~Victim()
{
	//Victim NAME just died for no apparent reason!
	std::cout << "Victim " << this->name << " just died for no apparent reason!" << std::endl;
}

std::string Victim::get_name() const
{
	return (this->name);
}

void Victim::getPolymorphed() const
{
	// NAME has been turned into a cute little sheep!
	std::cout << this->name << " has been turned into a cute little sheep!" << std::endl;
}

Victim& Victim::operator=(const Victim &src)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this == &src)
        return (*this);
    this->name = src.name;
    return (*this);
}

std::ostream &operator<<(std::ostream &out, const Victim &src)
{
	//I'm NAME and I like otters!
	out << "I'm " << src.get_name() << " and I like otters!" << std::endl;
	return (out);
}
