/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:25:56 by syamashi          #+#    #+#             */
/*   Updated: 2021/05/31 10:32:33 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_HPP
#define PLASMARIFLE_HPP

#include <iostream>
#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
	private:
    public:
        PlasmaRifle();
        ~PlasmaRifle();
        PlasmaRifle(const PlasmaRifle &src);
        PlasmaRifle& operator = (const PlasmaRifle &src);

		void attack() const;
};

#endif