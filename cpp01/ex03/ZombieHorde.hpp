/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 10:10:56 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/07 09:07:55 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

#include <iostream>
#include <string>
#include <time.h>
#include "Zombie.hpp"

class	ZombieHorde
{
	public:
		ZombieHorde(int N);
		~ZombieHorde();
		void	announce();
	private:
		int	N;
		Zombie*	Zs;
};

#endif