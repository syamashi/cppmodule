/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:06:39 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/07 10:48:18 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	srand(time(NULL));
	FragTrap f("SYAMASHI");
	std::cout << "--------------------FRAG_TRAP-------------------" << std::endl;
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
	return (0);
}
