/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:58:34 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/10 08:28:39 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", NULL);
		HumanA ANN("ANN", club);
		bob.attack();
		ANN.attack();
		club.setType("some other type of club");
		bob.attack();
		ANN.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		HumanB ANN("ANN");
		jim.setWeapon(club);
		ANN.setWeapon(club);
		jim.attack();
		ANN.attack();
		club.setType("some other type of club");
		jim.attack();
		ANN.attack();
	}
}
