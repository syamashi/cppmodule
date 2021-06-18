/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 21:22:09 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/18 13:07:58 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP

#include <iostream>
#include <time.h>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class NinjaTrap : virtual public ClapTrap
{
	public:
		NinjaTrap();
		NinjaTrap(const std::string &name);
		NinjaTrap(const NinjaTrap &src);
		~NinjaTrap();

		void ninjaShoebox(ClapTrap &crap);
		void ninjaShoebox(ScavTrap &scav);
		void ninjaShoebox(FragTrap &flag);
		void ninjaShoebox(NinjaTrap &ninja);

		NinjaTrap& operator=(const NinjaTrap &src);
	private:
};

std::ostream& operator<<(std::ostream& out, NinjaTrap const & src);
#endif