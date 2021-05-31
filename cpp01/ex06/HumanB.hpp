/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:07:56 by syamashi          #+#    #+#             */
/*   Updated: 2021/05/24 19:25:25 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
class HumanB
{
	public:
		HumanB(std::string name);
		void	setWeapon(Weapon &wp);
		void	attack();
	private:
		Weapon	*ptr;
		std::string	name;
};

#endif
