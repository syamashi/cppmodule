/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:09:28 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/18 22:51:25 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ISquad.hpp"
#include "Squad.hpp"
#include "ISpaceMarine.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

void pout(std::string mes)
{
	std::cout << std::endl << " ----- " << mes << " ----- " << std::endl;
}

int main()
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;
	ISquad* vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	delete vlc;

	ISquad *vlc2 = new Squad;
	pout("ann = new TacticalMarine");
	ISpaceMarine* ann = new TacticalMarine;
	pout("bil = new AssaultTerminator");
	ISpaceMarine* bil = new AssaultTerminator;
	int ret = 0;
	pout("vlc2->push(ann)");
	ret = vlc2->push(ann);
	std::cout << ret << std::endl;
	pout("vlc2->push(ann)");
	ret = vlc2->push(ann);
	std::cout << ret << std::endl;
	pout("vlc2->push(ann)");
	ret = vlc2->push(ann);
	std::cout << ret << std::endl;
	pout("vlc2->push(bil)");
	ret = vlc2->push(bil);
	std::cout << ret << std::endl;
	pout("vlc2->push(bil)");
	ret = vlc2->push(bil);
	std::cout << ret << std::endl;
	pout("vlc2->push(bil)");
	ret = vlc2->push(bil);
	std::cout << ret << std::endl;
	for (int i = 0; i < vlc2->getCount(); ++i)
	{
		std::cout << std::endl << " --- vlc2[" << i << "] --- " << std::endl;
		ISpaceMarine* cur = vlc2->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	pout("*cann = ann->clone()");
	ISpaceMarine *cann = ann->clone();
	cann->battleCry();
	cann->rangedAttack();
	cann->meleeAttack();

	pout("*cbil = bil->clone()");
	ISpaceMarine *cbil = bil->clone();
	cbil->battleCry();
	cbil->rangedAttack();
	cbil->meleeAttack();

	Squad squad;
	pout("squad.push(cann->clone())");
	ret = squad.push(cann->clone());
	std::cout << ret << std::endl;
	pout("squad.push(cbil->clone())");
	ret = squad.push(cbil->clone());
	std::cout << ret << std::endl;
	Squad esquad;
	pout("csquad(squad)");
	Squad csquad(squad);
	for (int i = 0; i < squad.getCount(); ++i)
	{
		std::cout << std::endl << " --- squad[" << i << "] --- " << std::endl;
		squad.getUnit(i)->battleCry();
		squad.getUnit(i)->meleeAttack();
		squad.getUnit(i)->rangedAttack();
		std::cout << std::endl << " --- csquad[" << i << "] --- " << std::endl;
		csquad.getUnit(i)->battleCry();
		csquad.getUnit(i)->meleeAttack();
		csquad.getUnit(i)->rangedAttack();
	}
	pout("csquad = squad");
	csquad = squad;
	for (int i = 0; i < squad.getCount(); ++i)
	{
		std::cout << std::endl << " --- csquad[" << i << "] --- " << std::endl;
		csquad.getUnit(i)->battleCry();
		csquad.getUnit(i)->meleeAttack();
		csquad.getUnit(i)->rangedAttack();
	}
	pout("delete cann");
	delete cann;
	pout("delete cbil");
	delete cbil;
	pout("delete vlc2");
	delete vlc2;
	pout("destructer");
	return 0;
}
