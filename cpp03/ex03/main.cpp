/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:06:39 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/07 10:29:35 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int main()
{
	srand(time(NULL));
	std::cout << "--------------------FRAG_TRAP-------------------" << std::endl;
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
	return (0);
}
