/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:48:27 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/20 16:42:02 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria *_inventory[4];
		int	_count;
    public:
        Character();
        virtual ~Character();
        Character(const Character &src);
        Character(const std::string &name);
        Character& operator = (const Character &src);

		std::string const & getName() const;
		std::string const & getInvtype(int idx) const;
		AMateria *const & getMateria(int idx) const;
		int const & getCount() const;
		bool isblank(int idx) const;

		void equip(AMateria* materia);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

std::ostream& operator<<(std::ostream &out, Character const &src);

#endif