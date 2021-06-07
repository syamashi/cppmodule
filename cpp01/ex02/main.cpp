/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 10:11:12 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/07 09:05:40 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

std::string	get_level(int lv)
{
	std::string	level;
	char c;

	for (; lv > 0; lv /= 10)
	{
		c = lv % 10 + '0';
		level = c + level;
	}
	level = "lv" + level;
	level += ":";
	return (level);
}

void	randomChump()
{
	std::string names[] = {"syam", "kyam", "tyam", "ryam", "pyam", "nyam", "myam", "xyam"};
	std::string types[] = {"zako", "tuyo", "oni", "gomi"};
	int	namesize = 8;
	int typesize = 4;
	int	seed = rand();
	std::string	t;

	t += get_level(seed % 100);
	t += types[seed % typesize];
	try
	{
		Zombie *z = new Zombie(names[seed % namesize], t);
		z->announce();
		delete z;
	}
	catch(std::bad_alloc)
	{
		std::cout << "bad_alloc" << std::endl;
	}
}

int main()
{
	srand(time(NULL));

	Zombie z("syamashi", "lv1:zako");
	z.announce();

	try
	{
		Zombie *z_heap = new Zombie("hyamashi", "lv2:zako");
		z_heap->announce();
		delete z_heap;
	}
	catch(std::bad_alloc)
	{
		std::cout << "bad_alloc" << std::endl;
	}

	ZombieEvent ze;
	ze.setZombieType("lv3:zako");
	Zombie *ze_heap = ze.newZombie("jyamashi");
	ze_heap->announce();
	delete ze_heap;

	for (int i = 0; i < 5; i++)
		randomChump();
}
