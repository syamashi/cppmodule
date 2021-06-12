/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 11:55:09 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/09 17:59:38 by syamashi         ###   ########.fr       */
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
	std::string names[] = {"syam", "kyam", "tyam", "ryam", "pyam", "nyam", "myam", "xyam"};
	std::string types[] = {"zako", "tuyo", "oni", "gomi"};
	int	namesize = 8;
	int typesize = 4;
	int	seed;

	this->N = N;
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
