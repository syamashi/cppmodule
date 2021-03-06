/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:37:09 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/08 16:40:40 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main()
{
	Phonebook	pb;
	std::string	cmd;
	while (1)
	{
		std::cout << PHONEBOOK;
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			pb.addcmd();
		else if (cmd == "SEARCH")
			pb.searchcmd();
		else if (cmd == "EXIT")
			pb.exitcmd();
		else
			std::cout << "[USAGE] ADD / SEARCH / EXIT" << std::endl;
	}
	return (0);
}
