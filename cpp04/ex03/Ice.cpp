/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:48:03 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/01 11:10:46 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(Ice const &src)
{
    *this = src;
}

Ice::~Ice()
{
}

Ice& Ice::operator=(const Ice &src)
{
    if (this == &src)
        return (*this);
    this->_type = src._type;
	this->_xp = src._xp;
    return (*this);
}

AMateria* Ice::clone() const
{
	try
	{
		Ice *ret = new Ice(*this);
		return (ret);
	}
	catch(std::bad_alloc)
	{
		std::cout << "bad_alloc" << std::endl;
		return (NULL);
	}
}

void Ice::use(ICharacter& target)
{
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
