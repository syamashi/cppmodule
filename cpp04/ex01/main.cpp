/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 23:14:13 by syamashi          #+#    #+#             */
/*   Updated: 2021/05/31 10:21:15 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"
#include "Character.hpp"
#include "Enemy.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"

int main()
{
	Character* me = new Character("me");
	std::cout << *me;
	Enemy* b = new RadScorpion();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	me->equip(pr);
	std::cout << *me;
	me->equip(pf);
	me->attack(b);
	std::cout << *me;
	me->equip(pr);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;

	std::cout << std::endl;
	std::cout << *pr << std::endl;
	std::cout << *pf << std::endl;
	Enemy* rad = new RadScorpion();
	std::cout << *rad << std::endl;
	Enemy* mut = new SuperMutant();
	std::cout << *mut << std::endl;
	me->attack(mut);
	std::cout << *mut << std::endl;
	std::cout << *me << std::endl;

	me->equip(pf);
	std::cout << *me << std::endl;

	me->attack(mut);
	std::cout << *mut << std::endl;
	std::cout << *me << std::endl;

	me->attack(mut);
	std::cout << *mut << std::endl;
	std::cout << *me << std::endl;

	me->attack(mut);
	std::cout << *mut << std::endl;
	std::cout << *me << std::endl;

	me->recoverAP();
	std::cout << *me << std::endl;

	me->recoverAP();
	std::cout << *me << std::endl;

	me->attack(mut);
	std::cout << *mut << std::endl;
	std::cout << *me << std::endl;

	me->attack(mut);
	std::cout << *me << std::endl;

//	pr = pf;
//	std::cout << *pr << std::endl;
	std::cout << "[pf = pr]: " << std::endl;
	pf = pr;
	std::cout << *pf << std::endl;

	Enemy *mut2 = new SuperMutant();
	std::cout << *mut2 << std::endl;

	mut2 = rad;
	std::cout << "[mut2 = rad]: " << std::endl << *mut2 << std::endl;

	Character *syamashi = new Character();
	std::cout << "[new Character()]: " << std::endl << *syamashi << std::endl;
	return 0;
}
