/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:48:12 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/20 16:18:33 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _count(0)
{
	for (int i = 0; i < 4; i++)
		this->_memory[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &src) : _count(0)
{
	for (int i = 0; i < 4; ++i)
		this->_memory[i] = NULL;
    operator=(src);
}

MateriaSource::~MateriaSource()
{
	// share materia data.
	for (int i = 0; i < 4; i++)
		delete this->_memory[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource &src)
{
    if (this == &src)
        return (*this);
	// share materia data. no need delete.
	for (int i = 0; i < 4; i++)
	{
		delete this->_memory[i];
		this->_memory[i] = NULL;
		if (src._memory[i])
		    this->_memory[i] = src._memory[i]->clone();
	}
	this->_count = src._count;
    return (*this);
}

std::string const &MateriaSource::getMemtype(int idx) const
{
	return (this->_memory[idx]->getType());
}

int const &MateriaSource::getCount() const
{
	return (this->_count);
}

bool MateriaSource::isBlank(int idx) const
{
	if (this->_memory[idx])
		return (false);
	return (true);
}

void MateriaSource::learnMateria(AMateria *materia)
{
	if (this->_count == 4)
		return ;
	if (!materia)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!this->_memory[i])
			continue;
		if (this->_memory[i] == materia)
			return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_memory[i])
			continue;
		this->_memory[i] = materia;
		++this->_count;
		break;
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_memory[i])
			continue;
		// me*のdeleteで消える
		if (this->_memory[i]->getType() == type)
			return (this->_memory[i]->clone());
	}
	return (NULL);
}

std::ostream& operator<<(std::ostream &out, MateriaSource const &src)
{
	for (int i = 0; i < 4; i++)
	{
		if (src.isBlank(i))
			out << "_memory[" << i << "]: " << "null" << std::endl;
		else
			out << "_memory[" << i << "]: " << src.getMemtype(i) << std::endl;
	}
	out << "_count: " << src.getCount() << std::endl;
	return (out);
}
