/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 13:55:47 by syamashi          #+#    #+#             */
/*   Updated: 2021/06/07 09:58:34 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook() : depth(0)
{
	for(int i = 0; i < MAXLINE; i++)
		for(int j = 0; j < 11; j++)
			this->info[i][j] = "";
}

void Phonebook::addcmd()
{
	std::string heads[11] = {
		"first_name",
		"last_name",
		"nickname",
		"login",
		"postal_address",
		"email_address",
		"phone_number",
		"birthday_date",
		"favorite_meal",
		"underwear_color",
		"darkest_secret"
	};
	bool	filled;

	if (depth >= MAXLINE)
	{
		std::cout << "[i]phonebook is full." << std::endl;
		return ;
	}
	filled = false;
	for (int i = FIRST_NAME; i <= DARKEST_SECRET; i++)
	{
		std::cout << "[" << std::setfill(' ') << std::setw(15);
		std::cout << heads[i] << "] < ";
		std::getline(std::cin, info[depth][i]);
		if (info[depth][i].size())
			filled = true;
	}
	if (!filled)
	{
		std::cout << "[i]nothing inputs" << std::endl;
		return ;
	}
		depth++;
};

void	Phonebook::searchcmd()
{
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|index     |first name|last name |nick name |" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	for (int i = 0; i < depth; i++)
	{
		std::cout << "|";
		std::cout << std::setfill(' ') << std::setw(10) << i;
		for (int j = FIRST_NAME; j <= NICKNAME; j++)
		{
			std::cout << "|";
			if (info[i][j].size() <= 10)
				std::cout << std::setfill(' ') << std::setw(10) << info[i][j];
			else
			{
				std::cout << info[i][j].substr(0, 9) << ".";
			}
		}
		std::cout << "|" << std::endl;
	}
	if (depth)
		std::cout << "+----------+----------+----------+----------+" << std::endl;
};

void Phonebook::exitcmd()
{
	std::cout << "EXIT" << std::endl;
	exit(0);
};
