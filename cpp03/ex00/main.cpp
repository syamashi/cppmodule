/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:06:39 by syamashi          #+#    #+#             */
/*   Updated: 2021/05/27 17:41:50 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	srand(time(NULL));
	FragTrap a;
	FragTrap f("SYAMASHI");
	std::cout << "--------------------FRAG_TRAP-------------------" << std::endl;
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
	return (0);
}
