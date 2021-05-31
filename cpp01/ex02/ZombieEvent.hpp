/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 10:10:56 by syamashi          #+#    #+#             */
/*   Updated: 2021/05/22 12:02:41 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include <iostream>
#include <string>
#include <time.h>
#include "Zombie.hpp"

class	ZombieEvent
{
	public:
		Zombie*	newZombie(std::string name);
		void	setZombieType(const std::string& type);
	private:
		std::string	type;
};

#endif