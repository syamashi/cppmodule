/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:16:13 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/20 16:51:37 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string _type;
		unsigned int _xp;
	public:
	    AMateria();
        AMateria(const AMateria &src);
		AMateria(std::string const & type);
        virtual ~AMateria();
        AMateria& operator = (const AMateria &src);

		std::string const & getType() const; //Returns the materia type
		unsigned int getXP() const; //Returns the Materia's XP

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

std::ostream& operator<<(std::ostream &out, AMateria const &src);

#endif
