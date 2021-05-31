/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:19:25 by syamashi          #+#    #+#             */
/*   Updated: 2021/05/31 10:44:56 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
#define AWEAPON_HPP

#include <iostream>
class AWeapon
{
	protected:
		std::string name;
		int damage;
		int apcost;
	private:
    public:
        AWeapon();
        AWeapon(const AWeapon &src);
		AWeapon(std::string const & name, int apcost, int damage);
        virtual ~AWeapon();

		std::string getName() const;
		int getAPcost() const;
		int getDamage() const;
		virtual void attack() const = 0; // no need .cpp

        AWeapon& operator=(const AWeapon &src);
};

std::ostream& operator<<(std::ostream &out, AWeapon const &src);

#endif