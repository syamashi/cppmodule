/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:19:54 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/07 17:00:44 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy() : hp(0), type("type")
{
}

Enemy::Enemy(int hp, std::string const & type) : hp(hp), type(type)
{
}

Enemy::Enemy(Enemy const &src)
{
    *this = src;
}

Enemy::~Enemy()
{
}

int Enemy::getHp() const
{
	return (this->hp);
}

std::string Enemy::getType() const
{
	return (this->type);
}

Enemy& Enemy::operator=(const Enemy &src)
{
    if (this == &src)
        return (*this);
	this->hp = src.hp;
	this->type = src.type;
    return (*this);
}

std::ostream& operator<<(std::ostream &out, Enemy const &src)
{
	out << "type: " << src.getType() << std::endl;
	out << "hp: " << src.getHp() << std::endl;
	return (out);
}
