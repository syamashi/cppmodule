/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:37:09 by syamashi          #+#    #+#             */
/*   Updated: 2021/05/21 20:22:15 by syamashi         ###   ########.fr       */
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
	}
	return (0);
}

^[A-Z][a-z]*([ ]+[A-Z][a-z]*){1,2}[,;:]((France[,:;]0\d(-\d\d){4})|(Japan[,;:]0\d\d(-\d{4}){2})|(((United States)|(Canada))[,;:](\d{3}-){2}\d{4}))$
^([A-Z][a-z]*)( +\1){1,2}([,;:])(France\30\d(-\d\d){4}|Japan\30(\d\d)(\5\6){2}|((United States|Canada)\3(\d\6-){2}\6\6))$