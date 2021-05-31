/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:25:13 by syamashi          #+#    #+#             */
/*   Updated: 2021/05/31 09:51:01 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTANT_HPP
#define SUPERMUTANT_HPP

#include <iostream>
#include "Enemy.hpp"

class SuperMutant : public Enemy
{
	private:
    public:
        SuperMutant();
        ~SuperMutant();
        SuperMutant(const SuperMutant &src);
        SuperMutant& operator = (const SuperMutant &src);
		void takeDamage(int damage);
};

#endif