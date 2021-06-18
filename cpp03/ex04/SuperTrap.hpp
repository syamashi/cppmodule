/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:46:33 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/18 13:12:15 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
#define SUPERTRAP_HPP

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
#include "ClapTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{
	public:
		SuperTrap();
		SuperTrap(const std::string &name);
		SuperTrap(const SuperTrap &name);
		~SuperTrap();
		void debug();

		void rangedAttack(const std::string &target);
		void meleeAttack(const std::string &target);

		SuperTrap& operator=(const SuperTrap &src);
	private:
};

std::ostream& operator<<(std::ostream &out, SuperTrap const &src);

#endif