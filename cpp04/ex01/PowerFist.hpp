/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:25:52 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/22 12:32:16 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP
#define POWERFIST_HPP

#include <iostream>
#include "AWeapon.hpp"

class PowerFist : public AWeapon
{
	private:
    public:
        PowerFist();
        virtual ~PowerFist();
        PowerFist(const PowerFist &src);
        PowerFist& operator = (const PowerFist &src);

		void attack() const;
};

#endif