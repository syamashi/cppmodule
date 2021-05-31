/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:07:56 by syamashi          #+#    #+#             */
/*   Updated: 2021/05/24 19:25:21 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
class HumanA
{
	public:
		HumanA(std::string name, Weapon& rwp);
		void	attack();
	private:
		Weapon&	rwp;
		std::string	name;
};

#endif
