/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:47:56 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/20 16:38:19 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("name")
{
}

Character::Character(Character const &src) : _name(src._name), _count(src._count)
{
	for (int i = 0; i < 4; ++i)
		this->_inventory[i] = NULL;
    operator=(src);
}

Character::Character(const std::string &name) : _name(name), _count(0)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::~Character()
{
	// copy must new...
	// but equip is not new...
	for (int i = 0; i < 4; i++)
	{
		delete this->_inventory[i];
		this->_inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character &src)
{
    if (this == &src)
        return (*this);
	for (int i = 0; i < 4; i++)
	{
		delete this->_inventory[i];
		this->_inventory[i] = NULL;
	}
	for (int i = 0; i < 4; i++)
	{
		if (src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
	}
	this->_count = src._count;
    return (*this);
}

std::string const & Character::getName() const
{
	return (this->_name);
}

std::string const & Character::getInvtype(int idx) const
{
	return (this->_inventory[idx]->getType());
}

AMateria *const & Character::getMateria(int idx) const
{
	return (this->_inventory[idx]);
}

int const & Character::getCount() const
{
	return (this->_count);
}

bool Character::isblank(int idx) const
{
	if (this->_inventory[idx])
		return (false);
	return (true);
}

void Character::equip(AMateria* materia)
{
	if (this->_count == 4)
		return ;
	if (!materia)
		return ;
	// already equip?
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == materia)
			return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			continue;
		this->_inventory[i] = materia;
		++this->_count;
		break;
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	if (!this->_inventory[idx])
		return ;
	this->_inventory[idx] = NULL;
	--this->_count;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return ;
	if (!this->_inventory[idx])
		return ;
	this->_inventory[idx]->use(target);
}

std::ostream& operator<<(std::ostream &out, Character const &src)
{
	out << "_name: " << src.getName() << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (src.isblank(i))
			out << "_inventory[" << i << "]: " << "null" << std::endl;
		else
			out << "_inventory[" << i << "]: " << src.getInvtype(i) << std::endl;
	}
	out << "_count: " << src.getCount() << std::endl;
	return (out);
}
