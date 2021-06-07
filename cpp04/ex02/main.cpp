/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:09:28 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/07 12:11:36 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ISquad.hpp"
#include "Squad.hpp"
#include "ISpaceMarine.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

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

	std::cout << std::endl << "-----double push test-----" << std::endl;
	ISquad *vlc2 = new Squad;
	ISpaceMarine* ann = new TacticalMarine;
	ISpaceMarine* bil = new AssaultTerminator;
	vlc2->push(ann);
	vlc2->push(ann);
	vlc2->push(ann);
	vlc2->push(bil);
	vlc2->push(bil);
	vlc2->push(bil);
	for (int i = 0; i < vlc2->getCount(); ++i)
	{
		std::cout << std::endl << " --- vlc2[" << i << "] --- " << std::endl;
		ISpaceMarine* cur = vlc2->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	delete vlc2;
	return 0;
}
