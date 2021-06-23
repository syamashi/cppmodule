/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:48:31 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/01 11:05:38 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
    private:
    public:
        Ice();
        virtual ~Ice();
        Ice(const Ice &src);
        Ice& operator = (const Ice &src);

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
