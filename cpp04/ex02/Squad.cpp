/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:40:47 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/22 14:34:32 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad() : count(0), units(NULL)
{
}

Squad::Squad(Squad const &src) : count(0), units(NULL)
{
    operator=(src);
}

Squad::~Squad()
{
	for (int i = 0; i < this->count; i++)
	{
		delete this->units[i];
		this->units[i] = NULL;
	}
	delete [] this->units;
	this->units = NULL;
}

int Squad::getCount() const
{
	return (this->count);
}

ISpaceMarine* Squad::getUnit(int n) const
{
	//getUnit(1) = unit[1] = count:2
	if (n < 0)
		return (NULL);
	if (n >= this->count)
		return (NULL);
	return (this->units[n]);
}

int Squad::push(ISpaceMarine *marine)
{
	if (!marine)
		return (this->count);
	// marineが同じだったらだめ
	for (int i = 0; i < this->count; i++)
	{
		if (this->units[i] == marine)
			return (this->count);
	}
	try
	{
		ISpaceMarine **ret = new ISpaceMarine*[this->count + 1];
		for (int i = 0; i < this->count; i++)
			ret[i] = this->units[i];
		ret[this->count] = marine;
		delete [] this->units;
		this->units = ret;
		++this->count;
		return (this->count);
	}
	catch(std::bad_alloc)
	{
		std::cout << "bad_alloc" << std::endl;
		exit (1);
	}
}

Squad& Squad::operator=(const Squad &src)
{
    if (this == &src)
        return (*this);
	if (this->units)
	{
		for (int i = 0; i < this->count; ++i)
		{
			delete this->units[i];
		}
		delete [] this->units;
		this->units = NULL;
	}
	this->units = new ISpaceMarine*[src.count];
	this->count = src.count;
	for (int i = 0; i < src.count; ++i)
	{
		this->units[i] = src.getUnit(i)->clone();
	}
	return (*this);
}
