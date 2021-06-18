/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:06:39 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/18 13:16:23 by syamashi         ###   ########.fr       */
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
	FragTrap f("SYAMASHI");
	f.rangedAttack("ENEMY1");
	f.meleeAttack("ENEMY2");
	std::cout << std::endl;
	unsigned int nums[] = {50, 40, 30, 20, 11, 10, 9};
	int numsize = 7;	for (int i = 0; i < numsize; i++)
		f.takeDamage(nums[i]);
	std::cout << std::endl;
	for (int i = 0; i < numsize; i++)
		f.beRepaired(nums[i]);
	std::cout << std::endl;
	for (int i = 0; i < 7; i++)
		f.vaulthunter_dot_exe("ENEMY3");
	std::cout << std::endl;
	std::cout << f << std::endl;

	std::cout << std::endl;
	std::cout << "--------------------SCAV_TRAP-------------------" << std::endl;
	ScavTrap s("SCAMASHI");
	std::cout << std::endl;
	s.rangedAttack("ENEMY1");
	s.meleeAttack("ENEMY2");
	std::cout << std::endl;
	for (int i = 0; i < numsize; i++)
		s.takeDamage(nums[i]);
	std::cout << std::endl;
	for (int i = 0; i < numsize; i++)
		s.beRepaired(nums[i]);
	std::cout << std::endl;
	for (int i = 0; i < 7; i++)
		s.challengeNewcomer("ENEMY3");
	std::cout << std::endl;
	std::cout << s << std::endl;

	std::cout << std::endl;
	std::cout << "--------------------NINJA_TRAP-------------------" << std::endl;
	NinjaTrap n("NYAMASHI");
	std::cout << std::endl;
	s.rangedAttack("ENEMY1");
	s.meleeAttack("ENEMY2");
	std::cout << std::endl;
	for (int i = 0; i < numsize; i++)
		n.takeDamage(nums[i]);
	std::cout << std::endl;
	for (int i = 0; i < numsize; i++)
		n.beRepaired(nums[i]);
	std::cout << std::endl;
	n.ninjaShoebox(f);
	n.ninjaShoebox(s);
	n.ninjaShoebox(n);
	std::cout << n << std::endl;
	std::cout << "--------------------SUPER_TRAP-------------------" << std::endl;
	SuperTrap sp("SSSMASHI");
	sp.rangedAttack("ENEMY1");
	sp.meleeAttack("ENEMY2");
	std::cout << std::endl;
	for (int i = 0; i < numsize; i++)
		sp.takeDamage(nums[i]);
	std::cout << std::endl;
	for (int i = 0; i < numsize; i++)
		sp.beRepaired(nums[i]);
	std::cout << std::endl;
	sp.ninjaShoebox(f);
	sp.ninjaShoebox(s);
	sp.ninjaShoebox(n);
	sp.vaulthunter_dot_exe("ENEMY3");
	std::cout << std::endl;
	std::cout << sp << std::endl;

	return (0);
}

