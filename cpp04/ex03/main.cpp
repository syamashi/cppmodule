/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 10:26:31 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/20 17:36:10 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

template <typename T>
void pout(T &a)
{
	std::cout << std::endl << " ----- " << a << " ----- " << std::endl;
}

// Your Character must have a constructor taking its name as parameter.
int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	pout("*ms1 = new MateriaSource");
	MateriaSource* ms1 = new MateriaSource;
	std::cout << *ms1 << std::endl;

	pout("ms1->learnMateria(new Ice())");
	ms1->learnMateria(new Ice());
	std::cout << *ms1 << std::endl;
	pout("ms1->learnMateria(new Cure())");
	ms1->learnMateria(new Cure());
	std::cout << *ms1 << std::endl;

	AMateria *cure = ms1->createMateria("cure"); // ms1 destructer affect delete.
	pout("ms1->learnMateria(cure)");
	ms1->learnMateria(cure);
	std::cout << *ms1 << std::endl;
	pout("ms1->learnMateria(cure): same pointer should not set.");
	ms1->learnMateria(cure);
	std::cout << *ms1 << std::endl;

	pout("MateriaSource ms2(ms1)");
	MateriaSource ms2(*ms1);
	std::cout << ms2 << std::endl;
	pout("ms2 = *ms1");
	ms2 = *ms1;
	std::cout << ms2 << std::endl;

	pout("Characer *syam = new Character(syam)");
	Character *syam = new Character("syam");
	std::cout << *syam << std::endl;

	pout("equip");
	syam->equip(ms2.createMateria("ice"));
	syam->equip(ms2.createMateria("ice"));
	syam->equip(ms2.createMateria("cure"));
	syam->equip(ms2.createMateria("cure"));
	std::cout << *syam << std::endl;

	pout("Character copysyam(*syam);");
	Character copysyam(*syam);
	std::cout << copysyam << std::endl;

	pout("copysyam = *syam;");
	copysyam = *syam;
	std::cout << copysyam << std::endl;

	AMateria *keep[4];
	for (int i = 0; i < 4; ++i)
		keep[i] = copysyam.getMateria(i);

	pout("unequip");
	for (int i = -1; i < 6; ++i)
		copysyam.unequip(i);
	std::cout << copysyam << std::endl;

	for (int i = 0; i < 4; ++i)
		delete keep[i];

	pout("use");
	for (int i = 0; i < 5; ++i)
	{
		syam->use(0, copysyam);
		std::cout << "XP: " << syam->getMateria(0)->getXP() << std::endl;
	}

	pout("AMateria *copyice(syam->getMateria(0))");
	AMateria *copyice(syam->getMateria(0));
	std::cout << *copyice << std::endl;

	pout("AMateria *equalice = copyice;");
	AMateria *equalice = copyice;
	std::cout << *equalice << std::endl;

	delete ms1;
	delete syam;
	return 0;
}
