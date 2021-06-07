/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 10:10:56 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/07 09:07:25 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <time.h>

class	Zombie
{
	public:
		Zombie(const std::string& name, const std::string& type);
		Zombie();
		~Zombie();
		void	announce();
		void	set_stats(std::string& name, std::string& type);
	private:
		std::string	name;
		std::string	type;
};

#endif