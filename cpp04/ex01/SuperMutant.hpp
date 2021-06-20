/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:25:13 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/18 15:36:04 by syamashi         ###   ########.fr       */
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
        virtual ~SuperMutant();
        SuperMutant(const SuperMutant &src);
        SuperMutant& operator = (const SuperMutant &src);
		void takeDamage(int damage);
};

#endif