/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 11:55:09 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/03 13:34:42 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

std::string	get_level(int lv)
{
	std::string	level;

	char	c;

	for (; lv > 0; lv /= 10)
	{
		c = lv % 10 + '0';
		level = c + level;
	}
	level = "lv" + level;
	level += ":";
	return (level);
}

ZombieHorde::ZombieHorde(int N)
{
	std::string names[] = {
		"syamashi",
		"kyamashi",
		"tyamashi",
		"ryamashi",
		"pyamashi",
		"nyamashi",
		"myamashi",
		"xyamashi"};
	std::string types[] = {
		"zako",
		"tuyo",
		"oni",
		"gomi"
	};
	int	namesize;
	int typesize;
	int	seed;

	this->N = N;
	namesize = 8;
	typesize = 4;
	try
	{
		this->Zs = new Zombie[N];
		for (int i = 0; i < N; i++)
		{
			std::string	t;
			seed = rand();
			t += get_level(seed % 100 + 1);
			t += types[seed % typesize];
			seed = rand();
			this->Zs[i].set_stats(names[seed % namesize], t);
		}
	}
	catch(std::bad_alloc)
	{
		std::cout << "bad_alloc" << std::endl;
		std::exit(1);
	}
}

ZombieHorde::~ZombieHorde()
{
	delete[] this->Zs;
}

void	ZombieHorde::announce()
{
	for(int i = 0; i < this->N; i++)
	{
		this->Zs[i].announce();
	}
}
