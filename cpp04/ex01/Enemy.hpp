/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:26:36 by syamashi          #+#    #+#             */
/*   Updated: 2021/05/31 09:50:51 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>

class Enemy
{
	protected:
		int hp;
		std::string type;
	private:
    public:
        Enemy();
		Enemy(int hp, std::string const & type);
        Enemy(const Enemy &src);
        virtual ~Enemy();
		int getHp() const;
		std::string getType() const;
		virtual void takeDamage(int damage) = 0;
		Enemy& operator = (const Enemy &src);
};

std::ostream& operator<<(std::ostream &out, Enemy const &src);

#endif
