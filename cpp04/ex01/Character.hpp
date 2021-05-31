/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:24:57 by syamashi          #+#    #+#             */
/*   Updated: 2021/05/30 20:37:17 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
	private:
		std::string name;
		int ap;
		AWeapon *aweapon;
    public:
        Character();
		Character(std::string const & name);
        Character(const Character &src);
        ~Character();
        Character& operator = (const Character &src);
		void recoverAP();
		void equip(AWeapon*);
		void attack(Enemy*);
		int getAp() const;
		std::string getAweaponName() const;
		std::string getName() const;
};

std::ostream& operator<<(std::ostream &out, Character const &src);

#endif