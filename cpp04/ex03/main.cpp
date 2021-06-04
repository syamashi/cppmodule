/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 10:26:31 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/01 20:11:46 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

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

	std::cout << "-----	tmp->getXP() -----" << std::endl;
	std::cout << "cure materia: " << tmp->getXP() << "XP" << std::endl;

	std::cout << "-----MateriaSource *MS1 = new MateriaSource-----" << std::endl;
	MateriaSource *MS1 = new MateriaSource;
	std::cout << *MS1 << std::endl;
	std::cout << "-----MateriaSource *MS2 = new MateriaSource-----" << std::endl;
	MateriaSource *MS2 = new MateriaSource;
	std::cout << *MS2 << std::endl;

	std::cout << "-----MS1->learnMateria(M1 : ice)-----" << std::endl;
	MS1->learnMateria(new Ice());
	std::cout << *MS1 << std::endl;
	std::cout << "-----MS1->learnMateria(M2 : cure)-----" << std::endl;
	MS1->learnMateria(new Cure());
	std::cout << *MS1 << std::endl;
	std::cout << "*-----MS2 = *MS1-----" << std::endl;
	*MS2 = *MS1;
	std::cout << "*MS2" << std::endl;
	std::cout << *MS2 << std::endl;
	std::cout << "*MS1" << std::endl;
	std::cout << *MS1 << std::endl;
	AMateria *M1 = MS1->createMateria("ice");
	AMateria *M2 = MS1->createMateria("cure");
	AMateria *M3 = MS2->createMateria("ice");
	AMateria *M4 = MS2->createMateria("cure");
	AMateria *M5 = MS2->createMateria("ice");
	std::cout << "-----	Character *syam = new Character(syam) -----" << std::endl;
	Character *syam = new Character("syam");
	std::cout << *syam << std::endl;
	std::cout << "-----syam->equip(M1 : ice)-----" << std::endl;
	syam->equip(M1);
	std::cout << *syam << std::endl;
	std::cout << "-----syam->equip(M1 : ice)-----" << std::endl;
	syam->equip(M1);
	std::cout << *syam << std::endl;
	std::cout << "-----syam->equip(M2 : cure)-----" << std::endl;
	syam->equip(M2);
	std::cout << *syam << std::endl;
	std::cout << "-----syam->equip(M3 : ice)-----" << std::endl;
	syam->equip(M3);
	std::cout << *syam << std::endl;
	std::cout << "-----syam->equip(M3 : ice)-----" << std::endl;
	syam->equip(M3);
	std::cout << *syam << std::endl;
	std::cout << "-----syam->equip(M4 : cure)-----" << std::endl;
	syam->equip(M4);
	std::cout << *syam << std::endl;
	std::cout << "-----syam->equip(M5 : ice)-----" << std::endl;
	syam->equip(M5);
	std::cout << *syam << std::endl;
	std::cout << "-----syam->unequip(2)-----" << std::endl;
	syam->unequip(2);
	std::cout << *syam << std::endl;
	std::cout << "-----new Character(csyam)-----" << std::endl;
	Character *csyam = new Character("csyam");
	std::cout << *csyam << std::endl;
	std::cout << "-----csyam->equip(M1 : ice)-----" << std::endl;
	csyam->equip(M1);
	std::cout << *csyam << std::endl;
	std::cout << "-----csyam = syam-----" << std::endl;
	*csyam = *syam;
	std::cout << *csyam << std::endl;
	std::cout << *syam << std::endl;
	std::cout << "-----csyam->unequip(-1)-----" << std::endl;
	csyam->unequip(-1);
	std::cout << *csyam << std::endl;
	std::cout << "-----csyam->unequip(4)-----" << std::endl;
	csyam->unequip(4);
	std::cout << *csyam << std::endl;
	std::cout << "-----csyam->unequip(3)-----" << std::endl;
	csyam->unequip(3);
	std::cout << *csyam << std::endl;
	std::cout << "-----csyam->unequip(0)-----" << std::endl;
	csyam->unequip(0);
	std::cout << *csyam << std::endl;
	std::cout << "-----csyam->unequip(2)-----" << std::endl;
	csyam->unequip(2);
	std::cout << *csyam << std::endl;
	std::cout << "-----csyam->unequip(2)-----" << std::endl;
	csyam->unequip(2);
	std::cout << *csyam << std::endl;
	std::cout << "-----csyam->unequip(1)-----" << std::endl;
	csyam->unequip(1);
	std::cout << *csyam << std::endl;
	std::cout << *syam << std::endl;

	delete bob;
	delete me;
	delete src;
	delete syam;
	delete csyam;
	delete MS1;
	delete MS2;
	return 0;
}
