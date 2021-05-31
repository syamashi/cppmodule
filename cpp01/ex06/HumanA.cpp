/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:11:17 by syamashi          #+#    #+#             */
/*   Updated: 2021/05/24 19:25:20 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& rwp) : name(name), rwp(rwp)
{
}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with his " << this->rwp.getType() << std::endl;
}
