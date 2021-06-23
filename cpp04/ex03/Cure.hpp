/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:48:31 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/23 13:20:09 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"


class Cure : public AMateria
{
    private:
    public:
        Cure();
        virtual ~Cure();
        Cure(const Cure &src);
        Cure& operator = (const Cure &src);

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
