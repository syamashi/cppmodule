/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 10:11:12 by syamashi          #+#    #+#             */
/*   Updated: 2021/05/22 17:29:28 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

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

void	randomChump()
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
	std::string	t;

	namesize = 8;
	typesize = 4;
	seed = rand();
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
		std::exit(1);
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
	catch(std::bad_alloc){
		std::cout << "bad_alloc" << std::endl;
		std::exit(1);
	}

	ZombieEvent ze;
	ze.setZombieType("lv3:zako");
	Zombie *ze_heap = ze.newZombie("jyamashi");
	ze_heap->announce();
	delete ze_heap;

	for (int i = 0; i < 5; i++)
		randomChump();
}
