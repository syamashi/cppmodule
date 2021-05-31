/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:06:39 by syamashi          #+#    #+#             */
/*   Updated: 2021/05/27 18:42:50 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int main()
{
	srand(time(NULL));
	std::cout << "--------------------FRAG_TRAP-------------------" << std::endl;
	FragTrap a;
	FragTrap f("SYAMASHI");
	f.rangedAttack("ENEMY1");
	f.meleeAttack("ENEMY2");
	std::cout << std::endl;
	int nums[] = {50, 40, 30, 20, 11, 10, 9};
	for (auto v: nums)
		f.takeDamage(v);
	std::cout << std::endl;
	for (auto v: nums)
		f.beRepaired(v);
	std::cout << std::endl;
	for (int i=0; i<7; i++)
		f.vaulthunter_dot_exe("ENEMY3");
	std::cout << std::endl;
	std::cout << f << std::endl;

	std::cout << std::endl;
	std::cout << "--------------------SCAV_TRAP-------------------" << std::endl;
	ScavTrap b;
	ScavTrap s("SCAMASHI");
	std::cout << std::endl;
	s.rangedAttack("ENEMY1");
	s.meleeAttack("ENEMY2");
	std::cout << std::endl;
	for (auto v: nums)
		s.takeDamage(v);
	std::cout << std::endl;
	for (auto v: nums)
		s.beRepaired(v);
	std::cout << std::endl;
	for (int i=0; i<7; i++)
		s.challengeNewcomer("ENEMY3");
	std::cout << std::endl;
	std::cout << s << std::endl;

	std::cout << std::endl;
	std::cout << "--------------------NINJA_TRAP-------------------" << std::endl;
	NinjaTrap c;
	NinjaTrap n("NYAMASHI");
	std::cout << std::endl;
	s.rangedAttack("ENEMY1");
	s.meleeAttack("ENEMY2");
	std::cout << std::endl;
	for (auto v: nums)
		n.takeDamage(v);
	std::cout << std::endl;
	for (auto v: nums)
		n.beRepaired(v);
	std::cout << std::endl;
	n.ninjaShoebox(f);
	n.ninjaShoebox(s);
	n.ninjaShoebox(n);
	std::cout << n << std::endl;
	std::cout << "--------------------SUPER_TRAP-------------------" << std::endl;
	SuperTrap d;
	SuperTrap sp("SSSMASHI");

	sp.rangedAttack("ENEMY1");
	sp.meleeAttack("ENEMY2");
	std::cout << std::endl;
	for (auto v: nums)
		sp.takeDamage(v);
	std::cout << std::endl;
	for (auto v: nums)
		sp.beRepaired(v);
	std::cout << std::endl;
	sp.ninjaShoebox(f);
	sp.ninjaShoebox(s);
	sp.ninjaShoebox(n);
	std::cout << std::endl;
	std::cout << sp << std::endl;

	return (0);
}

