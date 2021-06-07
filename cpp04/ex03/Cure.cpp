/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:48:03 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/07 12:14:54 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(Cure const &src)
{
    *this = src;
}

Cure::~Cure()
{
}

Cure& Cure::operator=(const Cure &src)
{
    if (this == &src)
        return (*this);
    this->_type = src._type;
	this->_xp = src._xp;
    return (*this);
}

AMateria* Cure::clone() const
{
	try
	{
		Cure *ret = new Cure(*this);
		return (ret);
	}
	catch(std::bad_alloc)
	{
		std::cout << "bad_alloc" << std::endl;
		return (NULL);
	}
}

void Cure::use(ICharacter& target)
{
	AMateria::use(target);
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
