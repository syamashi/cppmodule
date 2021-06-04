/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:18:42 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/01 14:43:35 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : AMateria("no name")
{
}

AMateria::AMateria(std::string const & type) : _type(type), _xp(0)
{
}

AMateria::AMateria(AMateria const &src)
{
    *this = src;
}

AMateria::~AMateria()
{
}

std::string const & AMateria::getType() const //Returns the materia type
{
	return (this->_type);
}

unsigned int AMateria::getXP() const //Returns the Materia's XP
{
	return (this->_xp);
}

void AMateria::use(ICharacter& target)
{
	this->_xp += 10;
}

AMateria& AMateria::operator=(const AMateria &src)
{
    if (this == &src)
        return (*this);
    this->_type = src._type;
	this->_xp = src._xp;
    return (*this);
}
