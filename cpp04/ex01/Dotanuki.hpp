/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dotanuki.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:25:56 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/20 21:30:10 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOTANUKI_HPP
#define DOTANUKI_HPP

#include <iostream>
#include "AWeapon.hpp"

class Dotanuki : public AWeapon
{
	private:
    public:
        Dotanuki();
        virtual ~Dotanuki();
        Dotanuki(const Dotanuki &src);
        Dotanuki& operator = (const Dotanuki &src);

		void attack() const;
};

#endif
