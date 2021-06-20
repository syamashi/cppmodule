/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mamuru.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:25:13 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/20 21:35:56 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAMURU_HPP
#define MAMURU_HPP

#include <iostream>
#include "Enemy.hpp"

class Mamuru : public Enemy
{
	private:
    public:
        Mamuru();
        virtual ~Mamuru();
        Mamuru(const Mamuru &src);
        Mamuru& operator = (const Mamuru &src);
		void takeDamage(int damage);
};

#endif