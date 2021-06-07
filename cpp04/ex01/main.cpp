/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 23:14:13 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/07 12:03:20 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"
#include "Character.hpp"
#include "Enemy.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"

void pout(std::string mes)
{
	std::cout << std::endl << "----- " << mes << " -----" << std::endl;
}

int main()
{
	pout("new Character(me)");
	Character* me = new Character("me");
	std::cout << *me;
	pout("new RadScorpion()");
	Enemy* radscorp = new RadScorpion();
	std::cout << *radscorp;
	pout("new PlasmaRifle()");
	AWeapon* pr = new PlasmaRifle();
	std::cout << *pr;
	pout("new PowerFist()");
	AWeapon* pf = new PowerFist();
	std::cout << *pf;
	pout("me->equip(pr)");
	me->equip(pr);
	std::cout << *me;
	pout("me->equip(pf)");
	me->equip(pf);
	std::cout << *me;
	pout("me->attack(radscorp)");
	me->attack(radscorp);
	std::cout << *radscorp;
	pout("me->equip(pf)");
	me->equip(pf);
	std::cout << *me;
	pout("me->attack(radscorp)");
	me->attack(radscorp);
	std::cout << *me;

	pout("new RadScorpion()");
	Enemy* rad = new RadScorpion();
	std::cout << *rad;
	pout("new SuperMutant()");
	Enemy* mut = new SuperMutant();
	std::cout << *mut;
	pout("me->attack(mut)");
	me->attack(mut);
	std::cout << *mut;
	pout("me->equip(pf)");
	me->equip(pf);
	std::cout << *me;

	pout("me->attack(mut)");
	me->attack(mut);
	std::cout << *mut;

	pout("me->attack(mut)");
	me->attack(mut);
	std::cout << *mut;
	std::cout << *me;

	pout("me->attack(mut)");
	me->attack(mut);
	std::cout << *mut;
	std::cout << *me;

	pout("me->recoverAP()");
	me->recoverAP();
	std::cout << *me;

	pout("me->recoverAP()");
	me->recoverAP();
	std::cout << *me;

	pout("me->attack(mut)");
	me->attack(mut);
	std::cout << *me;

	pout("pf = pr");
	delete pf;
	pf = pr;
	std::cout << *pf;

	pout("new SuperMutant()");
	Enemy *mut2 = new SuperMutant();
	std::cout << *mut2;

	pout("mut2 = rad");
	delete mut2;
	mut2 = rad;
	std::cout << *mut2;

	delete me;
	delete pr;
	delete rad;
	return 0;
}
