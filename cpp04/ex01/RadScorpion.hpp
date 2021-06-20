/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:25:41 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/18 15:35:58 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADSCORPION_HPP
#define RADSCORPION_HPP

#include <iostream>
#include "Enemy.hpp"

class RadScorpion : public Enemy
{
	private:
    public:
        RadScorpion();
        virtual ~RadScorpion();
        RadScorpion(const RadScorpion &src);
        RadScorpion& operator = (const RadScorpion &src);
		void takeDamage(int damage);
};

#endif