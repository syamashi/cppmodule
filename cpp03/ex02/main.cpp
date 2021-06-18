/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:06:39 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/18 12:41:57 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	srand(time(NULL));
	std::cout << "--------------------FRAG_TRAP-------------------" << std::endl;

	FragTrap f("SYAMASHI");
	f.rangedAttack("ENEMY1");
	f.meleeAttack("ENEMY2");
	std::cout << std::endl;
	unsigned int nums[] = {50, 40, 30, 20, 11, 10, 9};
	int numsize = 7;
	for (int i = 0; i < numsize; i++)
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
	return (0);
}
